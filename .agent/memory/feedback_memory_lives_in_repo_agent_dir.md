---
name: feedback-memory-lives-in-repo-agent-dir
description: メモリの実体は各リポジトリの .agent/memory に置き、ハーネス側のパスはそこへの symlink にする
metadata:
  type: feedback
---

メモリファイルは `~/.local/share/claude/projects/<encoded>/memory/` に直接置かず、各プロジェクトの `.agent/memory/` に実体を置いて、ハーネス側のパスをそこへの symlink にする。2026-09-10 に既存34プロジェクト・88件を一括移行済み。

**Why:** ハーネスのメモリ置き場は cwd をエンコードしたディレクトリ名で決まるため、プロジェクトを移動・rename するとメモリが孤立する。実体をリポジトリ内に持てば中身はリポジトリと一緒に移動する。

**How to apply:** 移動・clone のあとは `~/.local/bin/claude-memory-relink`（引数なしで `~/Documents` 以下を走査、引数でルート指定可）を実行して張り直す。dangling なリンクも同時に報告される。
