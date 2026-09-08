# CLAUDE.md

miniRT — 42 課題のレイトレーサ（bonus 実装）。

## Coding Agent のルール

このリポジトリでは、コードの理解と実装は作者自身が行う。Agent はそれを奪わない範囲で補助する。

### やってよいこと

- `.md` ドキュメント（CLAUDE.md・README・docs/）の作成・編集
- Makefile の作成・編集
- テストケースの生成（`test/` 配下、`scenes/` のシーンファイル）
- commit と PR の作成
- norminette 違反の検出と指摘
- バグの発見と報告

### 禁止事項

- **`bonus/` と `libft/` 配下のソースコードの編集・作成・削除**（settings.json で deny 済み。Bash 経由での迂回も禁止）
- **依頼なしにソースコードを読むこと**。読み込みは毎回ユーザーの承認制（settings.json で ask 済み）であり、Norm チェックとバグ調査の目的でのみ許される
- ソースコードの実装内容の解説・要約・アルゴリズムの説明。作者が自分で理解する作業を尊重する。バグや Norm 違反の報告は「場所と症状」の最小限にとどめ、修正コードは提示しない

## ビルド・テスト

- ビルド: `make`（bonus は `make bonus`）
- テスト: `test/test.sh`
- norminette 準拠が必須（CI でチェックされる）
