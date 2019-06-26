# efont UTF16 Font Data(SPIFFS)

http://openlab.ring.gr.jp/efont/unicode/

/efont/ Unicode Font をArduinoで使えるようにしました。

## 概要

/efont/ Unicode Fontに収録されているf16.bdfとb16.bdfを利用して1文字32バイトの16ピクセルフォントデータです。
全角文字はf16.bdfを利用し、U+00FFまでの文字は半角としb16.bdfを利用しています。

## 使い方

ダウンロードしたフォルダをArduinoのlibrariesフォルダにコピーをするか、必要なファイルだけプロジェクトの中にコピーしてください。

## フォントデータの転送

あらかじめefont.binをSPIFFSの転送ツールを使って転送しておいてください。
フォントデータ取得時間を短縮するために、複数の文字を一度に読み込んでから描画しています。バッファのサイズはデフォルト32文字ですが、変更することができます。

efontUTF16spiffs.hより前に、バッファサイズを宣言することで、変更することができます。


```
#define EFONT_BUF_SIZE 64
#include "efontUTF16spiffs.h"
```

## M5StickC以外での利用方法

描画周りについては機種ごとに違うため、各自機種に合わせて作り直してください。
