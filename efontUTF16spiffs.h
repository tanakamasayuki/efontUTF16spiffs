#ifndef __EFONT_UTF16_SPIFFS_H__
#define __EFONT_UTF16_SPIFFS_H__

#include <arduino.h>
#include "FS.h"
#include "SPIFFS.h"

#ifndef EFONT_BUF_SIZE
  #define EFONT_BUF_SIZE 32
#endif

const uint8_t efontUTF16FontTable[] = {
  0, // U+00XX
  1, // U+01XX
  2, // U+02XX
  3, // U+03XX
  4, // U+04XX
  255, // U+05XX
  255, // U+06XX
  255, // U+07XX
  255, // U+08XX
  5, // U+09XX
  255, // U+0AXX
  255, // U+0BXX
  255, // U+0CXX
  255, // U+0DXX
  255, // U+0EXX
  255, // U+0FXX
  255, // U+10XX
  255, // U+11XX
  255, // U+12XX
  255, // U+13XX
  255, // U+14XX
  255, // U+15XX
  255, // U+16XX
  255, // U+17XX
  255, // U+18XX
  255, // U+19XX
  255, // U+1AXX
  255, // U+1BXX
  255, // U+1CXX
  255, // U+1DXX
  6, // U+1EXX
  7, // U+1FXX
  8, // U+20XX
  9, // U+21XX
  10, // U+22XX
  11, // U+23XX
  12, // U+24XX
  13, // U+25XX
  14, // U+26XX
  15, // U+27XX
  255, // U+28XX
  255, // U+29XX
  255, // U+2AXX
  255, // U+2BXX
  255, // U+2CXX
  255, // U+2DXX
  255, // U+2EXX
  255, // U+2FXX
  16, // U+30XX
  17, // U+31XX
  18, // U+32XX
  19, // U+33XX
  20, // U+34XX
  21, // U+35XX
  22, // U+36XX
  23, // U+37XX
  24, // U+38XX
  25, // U+39XX
  26, // U+3AXX
  27, // U+3BXX
  28, // U+3CXX
  29, // U+3DXX
  30, // U+3EXX
  31, // U+3FXX
  32, // U+40XX
  33, // U+41XX
  34, // U+42XX
  35, // U+43XX
  36, // U+44XX
  37, // U+45XX
  38, // U+46XX
  39, // U+47XX
  40, // U+48XX
  41, // U+49XX
  42, // U+4AXX
  43, // U+4BXX
  44, // U+4CXX
  45, // U+4DXX
  46, // U+4EXX
  47, // U+4FXX
  48, // U+50XX
  49, // U+51XX
  50, // U+52XX
  51, // U+53XX
  52, // U+54XX
  53, // U+55XX
  54, // U+56XX
  55, // U+57XX
  56, // U+58XX
  57, // U+59XX
  58, // U+5AXX
  59, // U+5BXX
  60, // U+5CXX
  61, // U+5DXX
  62, // U+5EXX
  63, // U+5FXX
  64, // U+60XX
  65, // U+61XX
  66, // U+62XX
  67, // U+63XX
  68, // U+64XX
  69, // U+65XX
  70, // U+66XX
  71, // U+67XX
  72, // U+68XX
  73, // U+69XX
  74, // U+6AXX
  75, // U+6BXX
  76, // U+6CXX
  77, // U+6DXX
  78, // U+6EXX
  79, // U+6FXX
  80, // U+70XX
  81, // U+71XX
  82, // U+72XX
  83, // U+73XX
  84, // U+74XX
  85, // U+75XX
  86, // U+76XX
  87, // U+77XX
  88, // U+78XX
  89, // U+79XX
  90, // U+7AXX
  91, // U+7BXX
  92, // U+7CXX
  93, // U+7DXX
  94, // U+7EXX
  95, // U+7FXX
  96, // U+80XX
  97, // U+81XX
  98, // U+82XX
  99, // U+83XX
  100, // U+84XX
  101, // U+85XX
  102, // U+86XX
  103, // U+87XX
  104, // U+88XX
  105, // U+89XX
  106, // U+8AXX
  107, // U+8BXX
  108, // U+8CXX
  109, // U+8DXX
  110, // U+8EXX
  111, // U+8FXX
  112, // U+90XX
  113, // U+91XX
  114, // U+92XX
  115, // U+93XX
  116, // U+94XX
  117, // U+95XX
  118, // U+96XX
  119, // U+97XX
  120, // U+98XX
  121, // U+99XX
  122, // U+9AXX
  123, // U+9BXX
  124, // U+9CXX
  125, // U+9DXX
  126, // U+9EXX
  127, // U+9FXX
  255, // U+A0XX
  255, // U+A1XX
  255, // U+A2XX
  255, // U+A3XX
  255, // U+A4XX
  255, // U+A5XX
  255, // U+A6XX
  255, // U+A7XX
  255, // U+A8XX
  255, // U+A9XX
  255, // U+AAXX
  255, // U+ABXX
  128, // U+ACXX
  129, // U+ADXX
  130, // U+AEXX
  131, // U+AFXX
  132, // U+B0XX
  133, // U+B1XX
  134, // U+B2XX
  135, // U+B3XX
  136, // U+B4XX
  137, // U+B5XX
  138, // U+B6XX
  139, // U+B7XX
  140, // U+B8XX
  141, // U+B9XX
  142, // U+BAXX
  143, // U+BBXX
  144, // U+BCXX
  145, // U+BDXX
  146, // U+BEXX
  147, // U+BFXX
  148, // U+C0XX
  149, // U+C1XX
  150, // U+C2XX
  151, // U+C3XX
  152, // U+C4XX
  153, // U+C5XX
  154, // U+C6XX
  155, // U+C7XX
  156, // U+C8XX
  157, // U+C9XX
  158, // U+CAXX
  159, // U+CBXX
  160, // U+CCXX
  161, // U+CDXX
  162, // U+CEXX
  163, // U+CFXX
  164, // U+D0XX
  165, // U+D1XX
  166, // U+D2XX
  167, // U+D3XX
  168, // U+D4XX
  169, // U+D5XX
  170, // U+D6XX
  171, // U+D7XX
  255, // U+D8XX
  255, // U+D9XX
  255, // U+DAXX
  255, // U+DBXX
  255, // U+DCXX
  255, // U+DDXX
  255, // U+DEXX
  255, // U+DFXX
  255, // U+E0XX
  255, // U+E1XX
  255, // U+E2XX
  255, // U+E3XX
  255, // U+E4XX
  255, // U+E5XX
  255, // U+E6XX
  255, // U+E7XX
  255, // U+E8XX
  255, // U+E9XX
  255, // U+EAXX
  255, // U+EBXX
  255, // U+ECXX
  255, // U+EDXX
  255, // U+EEXX
  255, // U+EFXX
  255, // U+F0XX
  255, // U+F1XX
  255, // U+F2XX
  255, // U+F3XX
  255, // U+F4XX
  255, // U+F5XX
  255, // U+F6XX
  255, // U+F7XX
  255, // U+F8XX
  172, // U+F9XX
  173, // U+FAXX
  255, // U+FBXX
  255, // U+FCXX
  255, // U+FDXX
  174, // U+FEXX
  175, // U+FFXX
};

char* efontUFT8toUTF16( uint16_t *pUTF16, char *pUTF8 ) {

  // 1Byte Code
  if ( pUTF8[0] < 0x80 ) {
    // < 0x80 : ASCII Code
    *pUTF16 = pUTF8[0];
    return pUTF8 + 1;
  }

  // 2Byte Code
  if ( pUTF8[0] < 0xE0 )  {
    *pUTF16 = ( ( pUTF8[0] & 0x1F ) << 6 ) + ( pUTF8[1] & 0x3F );
    return pUTF8 + 2;
  }

  // 3Byte Code
  if ( pUTF8[0] < 0xF0 ) {
    *pUTF16 = ( ( pUTF8[0] & 0x0F ) << 12 ) + ( ( pUTF8[1] & 0x3F ) << 6 ) + ( pUTF8[2] & 0x3F );
    return pUTF8 + 3;
  } else {
    // 4byte Code
    *pUTF16 = 0;
    return pUTF8 + 4;
  }
}

void getefontData( uint8_t *font, uint16_t fontUTF16 ) {
  if ( efontUTF16FontTable[ fontUTF16 >> 8 ] != 255 ) {
    SPIFFS.begin(true);
    File fp = SPIFFS.open("/efont.bin", FILE_READ);
    if ( fp != NULL ) {
      fp.seek( efontUTF16FontTable[ fontUTF16 >> 8 ] * 32 * 256 + ( fontUTF16 & 0xff ) * 32 );
      fp.read( font, 32 );
    } else {
      // No Font
      memset( font, 0, 32 );
    }
    SPIFFS.end();
  } else {
    // No Font
    memset( font, 0, 32 );
  }
}

void getefontData( uint8_t font[EFONT_BUF_SIZE][32], uint16_t fontUTF16[EFONT_BUF_SIZE], uint8_t fontcount ) {
  SPIFFS.begin(true);
  File fp = SPIFFS.open("/efont.bin", FILE_READ);

  for ( int i = 0 ; i < fontcount ; i++ ) {
    if ( efontUTF16FontTable[ fontUTF16[i] >> 8 ] != 255 ) {
      if ( fp != NULL ) {
        fp.seek( efontUTF16FontTable[ fontUTF16[i] >> 8 ] * 32 * 256 + ( fontUTF16[i] & 0xff ) * 32 );
        fp.read( font[i], 32 );
      } else {
        // No Font
        memset( font[i], 0, 32 );
      }
    } else {
      // No Font
      memset( font[i], 0, 32 );
    }
  }
  SPIFFS.end();
}

#endif
