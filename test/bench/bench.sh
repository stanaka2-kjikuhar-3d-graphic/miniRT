#!/bin/bash

# 描画時間の計測スクリプト
#
#   bash test/bench/bench.sh [シーン...]
#
# シーンを省略すると test/bench/scenes/*.rt を全て計測する。
# 繰り返し回数は REPEAT、ビルド後の待ち時間は SETTLE で変えられる。
#   例: REPEAT=10 SETTLE=30 GAP=2 bash test/bench/bench.sh
#
# DEBUG ビルドは1フレーム描画して終了するので、プロセスの実時間を計測している。
# したがって計測値には X への接続・パース・画像転送の固定コスト (手元では約60ms)
# が含まれる。同じマシンでの相対比較には使えるが、フレーム時間の絶対値ではない。
#
# 計測を隙間なく連続実行すると値が大きく膨らむ (手元では約1.8倍) ため、
# 実行の間に GAP 秒あける。1秒以上あければ頭打ちになる。
# 同じ理由でフルビルド直後も避け、ビルドと計測の間に SETTLE 秒あける。
# さらにシーンを外側ではなく内側で回し、残った変動を全シーンに散らす。

PROGRAM=./miniRT
SCENE_DIR=test/bench/scenes
ERROR_LOG=test/bench/error.log
REPEAT=${REPEAT:-5}
SETTLE=${SETTLE:-20}
GAP=${GAP:-2}
WARMUP=2

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
	sleep "$GAP"
	echo "$sec" | awk '{printf "%.0f", $1 * 1000}'
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
echo "repeat  : $REPEAT (gap ${GAP}s)"
echo ""

# 描画せず即終了するシーンを先に弾く
STATUS=0
TARGETS=()
for scene in "${SCENES[@]}"; do
	[ -f "$scene" ] || continue
	if ! "$PROGRAM" "$scene" > /dev/null 2> "$ERROR_LOG"; then
		echo -e "${RED}FAIL${NC}: $scene (描画に失敗した)"
		cat "$ERROR_LOG"
		STATUS=1
		continue
	fi
	TARGETS+=("$scene")
done

if [ ${#TARGETS[@]} -eq 0 ]; then
	rm -f "$ERROR_LOG"
	exit 1
fi

# ビルドの熱が引くまで待つ
echo "=== Settling (${SETTLE}s) ==="
sleep "$SETTLE"
echo ""

# ウォームアップ
for ((i = 0; i < WARMUP; i++)); do
	for scene in "${TARGETS[@]}"; do
		run_once "$scene" > /dev/null
	done
done

# 計測。シーンを内側で回して、残った変動を全シーンに散らす
RESULT=$(mktemp)
for ((i = 0; i < REPEAT; i++)); do
	for scene in "${TARGETS[@]}"; do
		printf "%s\t%s\n" "$scene" "$(run_once "$scene")" >> "$RESULT"
	done
done

# 集計
echo "=== Benchmark (ms) ==="
printf "%-32s %8s %8s %8s\n" "scene" "median" "min" "max"
for scene in "${TARGETS[@]}"; do
	awk -F'\t' -v scene="$scene" '
		$1 == scene { v[++n] = $2 }
		END {
			for (i = 1; i < n; i++)
				for (j = i + 1; j <= n; j++)
					if (v[j] < v[i]) { t = v[i]; v[i] = v[j]; v[j] = t }
			if (n % 2) median = v[(n + 1) / 2]
			else median = (v[n / 2] + v[n / 2 + 1]) / 2
			printf "%-32s %8.0f %8.0f %8.0f\n", scene, median, v[1], v[n]
		}' "$RESULT"
done

echo ""
if [ $STATUS -eq 0 ]; then
	echo -e "${GREEN}done${NC}"
fi

rm -f "$ERROR_LOG" "$RESULT"
make fclean > /dev/null

exit $STATUS
