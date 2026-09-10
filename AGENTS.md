# AGENTS.md

miniRT — 42 課題のレイトレーサ（bonus 実装）。

## Coding Agent のルール

このリポジトリでは、コードの理解と実装は作者自身が行う。Agent はそれを奪わない範囲で補助する。

### やってよいこと

- `.md` ドキュメント（AGENTS.md・README・docs/）の作成・編集
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

## エディタ (clangd / LSP)

nvim の `gd`（定義ジャンプ）や補完は clangd が担う。索引の元になるのは
`compile_commands.json` で、これが無いと clangd は「開いているファイルとその
インクルード先」しか索引できず、`gd` がヘッダのプロトタイプ止まりになる。
`compile_flags.txt` はフラグの羅列だけで翻訳単位の一覧を持たないため代用にならない。

```sh
make fclean && bear -- make bonus   # compile_commands.json を生成
```

- ソースを追加・削除したら作り直す（`bear -- make re`）。
- 索引は `.cache/clangd/` に貯まる。`compile_commands.json` ともども gitignore 済み。
- 挙動が変なときは nvim で `:LspRestart`、`:checkhealth lsp` を見る。

## 蓄積知識

このプロジェクトで分かったことは `.agent/memory/` に 1 ファイル 1 件で置いてある。
`.agent/memory/MEMORY.md` が索引。作業前に目を通し、新しく分かったことは同じ形式で追記する。
