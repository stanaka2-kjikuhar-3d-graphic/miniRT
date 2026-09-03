#!/usr/bin/env bash
# 42-style header ("Updated: YYYY/MM/DD HH:MM:SS by <login>") の
# Updated 行を、今この瞬間の日時 & 固定のログイン名に書き換える。
#
# 使い方:
#   update-header.sh <file> [file ...]
#
# ・対象は *.c / *.h / Makefile のみ。それ以外は何もせず終了する。
# ・ファイル内に既存の "Updated: ... by <login>" 行が無ければ何もしない
#   （ヘッダの新規挿入はしない）。
# ・login の文字数が変わっても、後続のスペースを増減させてヘッダの
#   罫線・桁位置がズレないようにする。
set -euo pipefail

HEADER_LOGIN="${HEADER_LOGIN:-kjikuhar}"

is_target() {
  case "$1" in
    *.c|*.h) return 0 ;;
    */Makefile|Makefile) return 0 ;;
    *) return 1 ;;
  esac
}

now="$(date '+%Y/%m/%d %H:%M:%S')"

for file in "$@"; do
  [ -f "$file" ] || continue
  is_target "$file" || continue
  grep -qE 'Updated: [0-9]{4}/[0-9]{2}/[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2} by [A-Za-z0-9_]+' "$file" || continue

  awk -v now="$now" -v newlogin="$HEADER_LOGIN" '
    {
      line = $0
      if (match(line, /Updated: [0-9]{4}\/[0-9]{2}\/[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2} by [A-Za-z0-9_]+/)) {
        matched = substr(line, RSTART, RLENGTH)
        before  = substr(line, 1, RSTART - 1)
        after   = substr(line, RSTART + RLENGTH)
        n = split(matched, parts, " by ")
        oldlogin = parts[n]
        replacement = "Updated: " now " by " newlogin
        delta = length(oldlogin) - length(newlogin)
        if (delta > 0) {
          pad = ""
          for (i = 0; i < delta; i++) pad = pad " "
          after = pad after
        } else if (delta < 0) {
          removed = 0
          need = -delta
          while (removed < need && substr(after, 1, 1) == " ") {
            after = substr(after, 2)
            removed++
          }
        }
        line = before replacement after
      }
      print line
    }
  ' "$file" > "$file.tmp" && mv "$file.tmp" "$file"
done
