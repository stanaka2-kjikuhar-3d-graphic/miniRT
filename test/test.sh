#!/bin/bash

PASS=0
FAIL=0
TOTAL_FAIL=0
PROGRAM=./miniRT
TIMEOUT=60
ERROR_LOG=test/error.log

# 色
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'


# ビルド
echo "=== Building ==="
make re CFLAGS="-g -fsanitize=address,undefined" CPPFLAGS="-DDEBUG"

if [ $? -ne 0 ]; then
	echo -e "${RED}Build failed${NC}"
	exit 1
fi

echo ""

# タイムアウト
run_with_timeout() {
	"$@" &
	PID=$!
	(sleep $TIMEOUT; kill $PID 2>/dev/null) &
	WATCHER=$!
	wait $PID
	actual_code=$?
	kill $WATCHER 2>/dev/null
	wait $WATCHER 2>/dev/null
	echo $actual_code
}

# テスト
run_test() {
	local map=$1
	local expected_code=$2
	local expected_txt=$3  # 追加

	"$PROGRAM" "$map" 2>$ERROR_LOG &
	PID=$!
	(sleep $TIMEOUT; kill $PID 2>/dev/null) &
	WATCHER=$!
	wait $PID 2>/dev/null
	actual_code=$?
	kill $WATCHER 2>/dev/null
	wait $WATCHER 2>/dev/null

	if [ $actual_code -eq 143 ] || [ $actual_code -eq 137 ]; then
		echo -e "${RED}FAIL${NC}: ./miniRT $map (timeout)"
		((FAIL++))
		echo ""
		return
	fi

	if grep -q "ERROR: AddressSanitizer\|ERROR: LeakSanitizer\|runtime error:" $ERROR_LOG; then
		echo -e "${RED}FAIL${NC}: ./miniRT $map (sanitizer error)"
		cat $ERROR_LOG
		((FAIL++))
		echo ""
		return
	fi

	if [ $actual_code -eq 139 ]; then
		echo -e "${RED}FAIL${NC}: ./miniRT $map (segfault)"
		cat $ERROR_LOG
		((FAIL++))
		echo ""
		return
	fi

	if [ "$actual_code" -ne "$expected_code" ]; then
		echo -e "${RED}FAIL${NC}: ./miniRT $map (exit code: expected=$expected_code, actual=$actual_code)"
		cat $ERROR_LOG
		((FAIL++))
		echo ""
		return
	fi

	# expected.txtが渡されていれば比較
	if [ -n "$expected_txt" ] && [ -f "$expected_txt" ]; then
		if ! diff -q "$expected_txt" $ERROR_LOG > /dev/null; then
			echo -e "${RED}FAIL${NC}: ./miniRT $map (stderr mismatch)"
			echo "--- expected ---"
			echo "$(cat $expected_txt)"
			echo "--- actual ---"
			echo "$(cat $ERROR_LOG)"
			((FAIL++))
			echo ""
			return
		fi
	fi

	echo -e "${GREEN}PASS${NC}: ./miniRT $map"
	((PASS++))
	echo ""
}

# valid: exit 0を期待
echo "=== Valid test ==="
PASS=0
FAIL=0
for file in test/valid/*; do
	[ -f "$file" ] || continue
	run_test "$file" 0 ""
done

echo -e "${GREEN}$PASS passed${NC}, ${RED}$FAIL failed${NC}"
echo ""
TOTAL_FAIL=$((TOTAL_FAIL + FAIL))

# invalid: exit 1を期待
echo "=== Invalid test ==="
PASS=0
FAIL=0

run_test "" 1 ""
run_test "no_exist.rt" 1 ""
run_test "1.rt 2.rt" 1 ""

rm -f test/invalid/read.rt
cp test/valid/simple.rt test/invalid/read.rt
chmod -r test/invalid/read.rt
run_test "test/invalid/read.rt" 1 ""
rm -f test/invalid/read.rt

for case_dir in test/invalid/*/; do
	[ -d "$case_dir" ] || continue
	for file in "$case_dir"*.rt; do
		[ -f "$file" ] || continue
		run_test "$file" 1 "${file}.expected"
	done
done

echo -e "${GREEN}$PASS passed${NC}, ${RED}$FAIL failed${NC}"
TOTAL_FAIL=$((TOTAL_FAIL + FAIL))

# ppm: --ppm で画像を書き出して exit 0 とファイルの形を期待
echo "=== PPM test ==="
PASS=0
FAIL=0

run_ppm_test() {
	local map=$1
	local ppm
	ppm=$(basename "${map%.rt}").ppm

	rm -f "$ppm"
	"$PROGRAM" "$map" --ppm 2>$ERROR_LOG &
	PID=$!
	(sleep $TIMEOUT; kill $PID 2>/dev/null) &
	WATCHER=$!
	wait $PID 2>/dev/null
	actual_code=$?
	kill $WATCHER 2>/dev/null
	wait $WATCHER 2>/dev/null

	if [ "$actual_code" -ne 0 ] || grep -q "ERROR: AddressSanitizer\|ERROR: LeakSanitizer\|runtime error:" $ERROR_LOG; then
		echo -e "${RED}FAIL${NC}: ./miniRT $map --ppm (exit code: $actual_code)"
		cat $ERROR_LOG
		((FAIL++))
		echo ""
		rm -f "$ppm"
		return
	fi

	local magic width height max_value header_bytes expected actual
	magic=$(head -n 1 "$ppm")
	read -r width height < <(head -n 2 "$ppm" | tail -n 1)
	max_value=$(head -n 3 "$ppm" | tail -n 1)
	header_bytes=$(head -n 3 "$ppm" | wc -c)
	expected=$((header_bytes + width * height * 3))
	actual=$(wc -c < "$ppm")
	rm -f "$ppm"
	if [ "$magic" != "P6" ] || [ "$max_value" != "255" ] || [ "$expected" -ne "$actual" ]; then
		echo -e "${RED}FAIL${NC}: ./miniRT $map --ppm (ppm: magic=$magic max=$max_value size expected=$expected actual=$actual)"
		((FAIL++))
		echo ""
		return
	fi

	echo -e "${GREEN}PASS${NC}: ./miniRT $map --ppm"
	((PASS++))
	echo ""
}

# 不正なオプションは exit 1 を期待
run_option_test() {
	local map=$1
	local options=$2

	"$PROGRAM" "$map" $options 2>$ERROR_LOG
	actual_code=$?
	if [ "$actual_code" -ne 1 ]; then
		echo -e "${RED}FAIL${NC}: ./miniRT $map $options (exit code: expected=1, actual=$actual_code)"
		cat $ERROR_LOG
		((FAIL++))
		echo ""
		return
	fi
	echo -e "${GREEN}PASS${NC}: ./miniRT $map $options"
	((PASS++))
	echo ""
}

run_ppm_test test/valid/simple.rt
run_option_test test/valid/simple.rt "--foo"
run_option_test test/valid/simple.rt "--ppm --ppm"

echo -e "${GREEN}$PASS passed${NC}, ${RED}$FAIL failed${NC}"
TOTAL_FAIL=$((TOTAL_FAIL + FAIL))

rm -f $ERROR_LOG
make fclean

if [ $TOTAL_FAIL -gt 0 ]; then
	exit 1
fi
