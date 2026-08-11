#!/bin/bash

# 描画時間の計測スクリプト
#
#   bash test/bench/bench.sh [シーン...]
#
# シーンを省略すると test/bench/scenes/*.rt を全て計測する。
# 繰り返し回数は REPEAT で変えられる (例: REPEAT=10 bash test/bench/bench.sh)。
#
# DEBUG ビルドは1フレーム描画して終了するので、プロセスの実時間を計測している。
# したがって計測値には X への接続・パース・画像転送の固定コスト (手元では約60ms)
# が含まれる。同じマシンでの相対比較には使えるが、フレーム時間の絶対値ではない。

PROGRAM=./miniRT
SCENE_DIR=test/bench/scenes
ERROR_LOG=test/bench/error.log
REPEAT=${REPEAT:-5}

# 色
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

if [ -z "$DISPLAY" ]; then
	echo -e "${RED}DISPLAY が設定されていない${NC}"
	echo "X サーバが必要。手元で画面を出さずに回すなら Xvfb を使う:"
	echo "  Xvfb :99 -screen 0 1400x900x24 &"
	echo "  DISPLAY=:99 bash test/bench/bench.sh"
	exit 1
fi

# 計測対象
if [ $# -gt 0 ]; then
	SCENES=("$@")
else
	SCENES=("$SCENE_DIR"/*.rt)
fi

# ビルド
echo "=== Building ==="
make re CPPFLAGS="-DDEBUG"

if [ $? -ne 0 ]; then
	echo -e "${RED}Build failed${NC}"
	exit 1
fi

echo ""

# 1回実行して実時間をミリ秒で返す
run_once() {
	local scene=$1
	local sec

	TIMEFORMAT='%3R'
	sec=$( { time "$PROGRAM" "$scene" > /dev/null 2>&1; } 2>&1 )
	echo "$sec" | awk '{printf "%.0f", $1 * 1000}'
}

# 中央値・最小・最大を出す
summarize() {
	local scene=$1
	shift
	printf '%s\n' "$@" | sort -n | awk -v scene="$scene" -v n=$# '
		{ v[NR] = $1 }
		END {
			if (n % 2) median = v[(n + 1) / 2]
			else median = (v[n / 2] + v[n / 2 + 1]) / 2
			printf "%-32s %8.0f %8.0f %8.0f\n", scene, median, v[1], v[n]
		}'
}

# 環境
echo "=== Environment ==="
echo "uname   : $(uname -srm)"
if [ "$(uname -s)" = "Darwin" ]; then
	echo "cpu     : $(sysctl -n machdep.cpu.brand_string) ($(sysctl -n hw.ncpu) cores)"
else
	echo "cpu     : $(grep -m1 'model name' /proc/cpuinfo | cut -d: -f2 | sed 's/^ //') ($(nproc) cores)"
fi
echo "threads : $(grep -m1 'define THREAD_COUNT' bonus/include/config.h | awk '{print $NF}')"
echo "commit  : $(git rev-parse --short HEAD 2>/dev/null || echo unknown)"
echo "repeat  : $REPEAT"
echo ""

# 計測
echo "=== Benchmark (ms) ==="
printf "%-32s %8s %8s %8s\n" "scene" "median" "min" "max"

STATUS=0
for scene in "${SCENES[@]}"; do
	[ -f "$scene" ] || continue

	# 1回目は捨てる。同時に、描画せず即終了するシーンを弾く
	if ! "$PROGRAM" "$scene" > /dev/null 2> "$ERROR_LOG"; then
		echo -e "${RED}FAIL${NC}: $scene (描画に失敗した)"
		cat "$ERROR_LOG"
		STATUS=1
		continue
	fi

	times=()
	for ((i = 0; i < REPEAT; i++)); do
		times+=("$(run_once "$scene")")
	done

	summarize "$scene" "${times[@]}"
done

echo ""
if [ $STATUS -eq 0 ]; then
	echo -e "${GREEN}done${NC}"
fi

rm -f "$ERROR_LOG"
make fclean > /dev/null

exit $STATUS
