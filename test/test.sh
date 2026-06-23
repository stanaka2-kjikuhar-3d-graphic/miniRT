#!/bin/bash

PASS=0
FAIL=0
PROGRAM=./miniRT
TIMEOUT=30
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
	expected_txt=""
	[ -f "${case_dir}expected.txt" ] && expected_txt="${case_dir}expected.txt"
	for file in "$case_dir"*; do
		[ -f "$file" ] || continue
		[ "$(basename $file)" = "expected.txt" ] && continue
		run_test "$file" 1 "$expected_txt"
	done
done

echo -e "${GREEN}$PASS passed${NC}, ${RED}$FAIL failed${NC}"

rm -f $ERROR_LOG
make fclean
