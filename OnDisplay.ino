#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 4, /* data=*/ 5, /* reset=*/ U8X8_PIN_NONE);

void setDisplay() {
  u8g2.begin();
}

void onDisplay(String top, String bottom) {
    const char* a = top.c_str();
    const char* b = bottom.c_str();
    const int tl = u8g2.getDisplayWidth();
    const int al = (tl - u8g2.getUTF8Width(a)) / 2;
    const int bl = (tl - u8g2.getUTF8Width(b)) / 2;

  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(al, 12, a);	// write something to the internal memory
  u8g2.drawStr(bl, 30, b);	// write something to the internal memory
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000); 
}

void onDisplayC(String top, String center, String bottom) {
    const char* a = top.c_str();
    const char* b = bottom.c_str();
    const char* c = center.c_str();
    const int tl = u8g2.getDisplayWidth();
    const int al = (tl - u8g2.getUTF8Width(a)) / 2;
    const int bl = (tl - u8g2.getUTF8Width(b)) / 2;
    const int cl = (tl - u8g2.getUTF8Width(c)) / 2;

  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(al, 10, a);	// write something to the internal memory
  u8g2.drawStr(cl, 20, c);	// write something to the internal memory
  u8g2.drawStr(bl, 30, b);	// write something to the internal memory
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000);
}
