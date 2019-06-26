#ifndef __EFONT_UTF16_SPIFFS_M5STICKC_H__
#define __EFONT_UTF16_SPIFFS_M5STICKC_H__

#include <M5StickC.h>
#include "efontUTF16spiffs.h"

#define EFONT_UTF16_DEBUG

void printEfont(char *str) {
  int posX = M5.Lcd.getCursorX();
  int posY = M5.Lcd.getCursorY();
  uint8_t textsize = M5.Lcd.textsize;
  uint32_t textcolor = M5.Lcd.textcolor;
  uint32_t textbgcolor = M5.Lcd.textbgcolor;
  
  byte fontbuf[EFONT_BUF_SIZE][32];
  uint8_t fontwidth[EFONT_BUF_SIZE];
  uint8_t fontindex = 0;
  uint16_t strUTF16[EFONT_BUF_SIZE];

  while( *str != 0x00 ){
    if( *str == '\n' ){
        break;
    }
    if( fontindex == EFONT_BUF_SIZE ){
        break;
    }
    
    // UTF16取得
    str = efontUFT8toUTF16( &strUTF16[fontindex], str );

    // 文字横幅
    int width = 16 * textsize;
    if( strUTF16[fontindex] < 0x0100 ){
      // 半角
      width = 8 * textsize;
    }
    
    fontwidth[fontindex] = width;

    fontindex++;
  }

  // フォント取得
  getefontData( fontbuf, strUTF16, fontindex );
  
  for( int i = 0 ; i < fontindex ; i++ ){
    // フォント取得
    byte* font = fontbuf[i];

    // 文字横幅
    int width = fontwidth[i];

#ifdef EFONT_UTF16_DEBUG
    Serial.printf( "str : U+%04X X:%d Y:%d W:%d\n", strUTF16[i], posX, posY, width );
#endif

    // 背景塗りつぶし
    M5.Lcd.fillRect(posX, posY, width, 16 * textsize, textbgcolor);

    // 取得フォントの確認
    for (uint8_t row = 0; row < 16; row++) {
      word fontdata = font[row*2] * 256 + font[row*2+1];
      for (uint8_t col = 0; col < 16; col++) {
#ifdef EFONT_UTF16_DEBUG
        Serial.write( ( (0x8000 >> col) & fontdata ) ? "#" : " " );
#endif
        if( (0x8000 >> col) & fontdata ){
          int drawX = posX + col * textsize;
          int drawY = posY + row * textsize;
          if( textsize == 1 ){
            M5.Lcd.drawPixel(drawX, drawY, textcolor);
          } else {
            M5.Lcd.fillRect(drawX, drawY, textsize, textsize, textcolor);
          }
        }
      }
#ifdef EFONT_UTF16_DEBUG
        Serial.write( "\n" );
#endif
    }

    // 描画カーソルを進める
    posX += width;

    // 折返し処理
    if( M5.Lcd.width() <= posX ){
      posX = 0;
      posY += 16 * textsize;
    }
  }

  if( *str == '\n' ){
    // 改行
    posY += 16 * textsize;
    posX = 0;
    str++;
  }

  // カーソルを更新
  M5.Lcd.setCursor(posX, posY);

  // 続きがあるので描画
  if( *str != 0x00 ){
    printEfont(str);
  }
}


void printEfont(char *str, int x, int y) {
  M5.Lcd.setCursor(x, y);
  printEfont(str);
}

void printEfont(char *str, int x, int y, int textsize) {
  M5.Lcd.setCursor(x, y);
  M5.Lcd.textsize = textsize;
  printEfont(str);
}

#endif
