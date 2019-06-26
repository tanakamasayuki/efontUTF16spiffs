#include <M5StickC.h>
//#define EFONT_BUF_SIZE 64
#include "efontUTF16spiffsM5StickC.h"

void setup() {
  M5.begin();
  M5.Lcd.setRotation(0);
  M5.Lcd.setCursor(0, 0);

  printEfont("新しい朝が来た希望の朝がabcd12345()+-１２３４５", 0, 16*0);
}

void loop() {
}
