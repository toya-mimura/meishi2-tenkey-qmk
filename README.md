# meishi2 Binary Numpad ビルドガイド

meishi2 を「フィンガーバイナリーテンキー」に改造するための手順書です。

## キーマップ

左手に置いて使います。小指側が最上位ビット(8)、人差指側が最下位ビット(1)です。

| 2進数 | 小指 | 薬指 | 中指 | 人差指 | 出力 |
|-------|------|------|------|--------|------|
| 0001  |      |      |      | ●      | 1    |
| 0010  |      |      | ●    |        | 2    |
| 0011  |      |      | ●    | ●      | 3    |
| 0100  |      | ●    |      |        | 4    |
| 0101  |      | ●    |      | ●      | 5    |
| 0110  |      | ●    | ●    |        | 6    |
| 0111  |      | ●    | ●    | ●      | 7    |
| 1000  | ●    |      |      |        | 8    |
| 1001  | ●    |      |      | ●      | 9    |
| 1010  | ●    |      | ●    |        | 0    |
| 1011  | ●    |      | ●    | ●      | +    |
| 1100  | ●    | ●    |      |        | -    |
| 1101  | ●    | ●    |      | ●      | *    |
| 1110  | ●    | ●    | ●    |        | /    |
| 1111  | ●    | ●    | ●    | ●      | .    |


---

## 必要なもの

- meishi2 キーボード（組み立て済み）
- USB ケーブル（meishi2 と PC を接続するもの）
- Windows PC（MSI ゲーミング PC を推奨）

---

## Step 1: QMK MSYS のインストール

QMK MSYS は、QMK ファームウェアをビルドするための Windows 用ツールです。
gcc などのビルドツールが全部入りなので、これだけ入れれば OK です。

1. 以下の URL を開く:
   https://msys.qmk.fm/
2. 「Latest Version」の `.exe` をダウンロード
3. ダウンロードした `.exe` を実行してインストール
4. インストールが完了したら **QMK MSYS** を起動（スタートメニューから）

---

## Step 2: QMK のセットアップ

QMK MSYS を起動すると、コマンド入力画面（黒い画面）が出ます。
以下のコマンドを **1行ずつ** コピペして Enter を押してください。

### 2-1. QMK のセットアップ（初回のみ・数分かかります）

```
qmk setup
```

途中で `Would you like to set up your QMK home in ...?` と聞かれたら **y** を入力して Enter。
`Would you like to clone ...?` と聞かれたら **y** を入力して Enter。

ダウンロードが始まります。数分〜十数分かかることがあります。気長に待ちましょう。

### 2-2. セットアップの確認

完了したら、以下を実行して meishi2 のデフォルトファームウェアがビルドできるか確認します:

```
qmk compile -kb biacco42/meishi2 -km default
```

最後に `[OK]` や `Linking: .build/biacco42_meishi2_default.hex` のような表示が出れば成功です。

---

## Step 3: カスタムキーマップの配置

ここから、Binary Numpad 用のキーマップファイルを所定の場所にコピーします。

### 3-1. キーマップフォルダの作成

```
mkdir -p ~/qmk_firmware/keyboards/biacco42/meishi2/keymaps/binary_numpad
```

### 3-2. ファイルのコピー

ダウンロードした3つのファイル（`keymap.c`, `config.h`, `rules.mk`）を、
以下のフォルダに入れてください:

```
C:\Users\（あなたのユーザー名）\qmk_firmware\keyboards\biacco42\meishi2\keymaps\binary_numpad\
```

Windows のエクスプローラーで上記フォルダを開いて、ファイルをドラッグ＆ドロップでOKです。

**または**、QMK MSYS で以下のコマンドを実行してもOKです（ファイルをホームに置いた場合）:

```
cp ~/keymap.c ~/qmk_firmware/keyboards/biacco42/meishi2/keymaps/binary_numpad/
cp ~/config.h ~/qmk_firmware/keyboards/biacco42/meishi2/keymaps/binary_numpad/
cp ~/rules.mk ~/qmk_firmware/keyboards/biacco42/meishi2/keymaps/binary_numpad/
```

---

## Step 4: ビルド＆書き込み

### 4-1. meishi2 を USB で PC に接続する

### 4-2. 以下のコマンドを実行

```
qmk flash -kb biacco42/meishi2 -km binary_numpad
```

ビルドが始まり、最後に以下のようなメッセージが表示されます:

```
Detecting USB port, reset your controller now...
```

### 4-3. meishi2 のリセットボタンを押す

この表示が出たら、meishi2 の **リセットボタン**（小さいタクトスイッチ）を **2回** 押してください。

自動的に書き込みが始まり、完了すると meishi2 が再起動します。

### 4-4. 動作確認

テキストエディタ（メモ帳など）を開いて、各キーや同時押しを試してください。

- 人差指だけ押す → `1` が入力される
- 中指だけ押す → `2` が入力される
- 中指＋人差指を同時に押す → `3` が入力される
- 4本全部同時に押す → `.` が入力される

---

## トラブルシューティング

### 同時押しがうまく認識されない

`config.h` の `COMBO_TERM` の値を大きくしてみてください（例: 100 → 150）。
値を大きくすると「同時押し」と判定する時間の猶予が広がります。
ただし、大きすぎると単独キーの反応が遅くなります。

変更後は Step 4 のビルド＆書き込みをやり直してください。

### 単独キーを押したのに数字が出ない / 変な文字が出る

USB を一度抜き差ししてみてください。
それでもダメなら、Step 4 をもう一度やり直してみてください。

### ビルドでエラーが出る

`qmk setup` をもう一度実行してみてください。
それでも解決しない場合は、エラーメッセージをコピーして相談してください。

### 元に戻したい

デフォルトの Ctrl+Z/X/C/V キーマップに戻したい場合:

```
qmk flash -kb biacco42/meishi2 -km default
```

を実行して、リセットボタンを押せば元に戻ります。

---

## ファイル構成

```
keyboards/biacco42/meishi2/keymaps/binary_numpad/
├── keymap.c   ... キーマップ本体（単独キー＋コンボの定義）
├── config.h   ... コンボの判定時間などの設定
└── rules.mk   ... コンボ機能の有効化
```

---

## カスタマイズのヒント

### キーマップを変更したい

`keymap.c` の `combo_t key_combos[]` テーブルで出力キーコードを変更できます。
QMK のキーコード一覧: https://docs.qmk.fm/keycodes

### COMBO_TERM（同時押し判定時間）を調整したい

`config.h` の `#define COMBO_TERM 100` の数値を変更します。

| 値      | 特徴                                   |
|---------|----------------------------------------|
| 30〜50  | 反応が速いが、同時押しの判定がシビア   |
| 50〜80  | バランスが良い                         |
| 80〜150 | 同時押しが楽だが、単独キーの反応が遅い |
