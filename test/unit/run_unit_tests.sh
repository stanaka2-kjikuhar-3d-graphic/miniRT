#!/bin/bash
# Builds and runs the matrix unit tests: one binary per test_*.c file
# (one file = one tested function), no external framework.

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
OBJ_DIR="$ROOT/test/unit/.bin"
mkdir -p "$OBJ_DIR"

CC_FLAGS=(-Wall -Wextra -Werror -Wconversion -Wno-sign-conversion -Wshadow \
	-I"$ROOT/bonus/include" \
	-I"$ROOT/bonus/include/scene" \
	-I"$ROOT/bonus/include/utils" \
	-I"$ROOT/libft/include" \
	-I"$ROOT/test/unit")

MATRIX_SRCS=("$ROOT"/bonus/src/utils/matrix/*.c \
	"$ROOT"/bonus/src/utils/matrix/internal/*.c \
	"$ROOT"/bonus/src/utils/vector/vec3/*.c \
	"$ROOT"/bonus/src/utils/vector/vec4/*.c)

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

total_pass=0
total_fail=0
files_failed=0

for test_file in "$ROOT"/test/unit/matrix/test_*.c; do
	name="$(basename "$test_file" .c)"
	bin="$OBJ_DIR/$name"
	echo "== $name =="
	if ! cc "${CC_FLAGS[@]}" "$test_file" "${MATRIX_SRCS[@]}" -lm -o "$bin" 2>&1; then
		echo -e "${RED}build failed${NC}"
		files_failed=$((files_failed + 1))
		continue
	fi
	output="$("$bin")"
	echo "$output"
	if [ $? -ne 0 ]; then
		files_failed=$((files_failed + 1))
	fi
	counts="$(echo "$output" | tail -n 1)"
	total_pass=$((total_pass + $(echo "$counts" | grep -oE '^[0-9]+')))
	total_fail=$((total_fail + $(echo "$counts" | grep -oE '[0-9]+ failed' | grep -oE '^[0-9]+')))
	echo ""
done

echo "=================================="
if [ "$files_failed" -eq 0 ]; then
	echo -e "${GREEN}all matrix unit tests passed (${total_pass} checks)${NC}"
else
	echo -e "${RED}${files_failed} test file(s) failed (${total_pass} passed, ${total_fail} failed)${NC}"
fi
exit "$files_failed"
