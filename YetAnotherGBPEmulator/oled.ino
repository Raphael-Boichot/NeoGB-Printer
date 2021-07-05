#ifdef USE_OLED

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#ifndef OLED_SDA
#define OLED_SDA 21
#endif
#ifndef OLED_SCL
#define OLED_SCL 22
#endif

#define PRINTER_ICON_HEIGHT 27
#define PRINTER_ICON_WIDTH 32

const unsigned char splashScreenlogo [] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0xe6, 0x31, 0x3e, 0x78, 0x74, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x07, 0x2e, 0x33, 0x30, 0x6d, 0x9e, 0xc0, 0x00, 0x00, 0x01, 0xf8, 0x00, 
  0x00, 0x01, 0x80, 0x00, 0x0e, 0x0e, 0x73, 0x30, 0x65, 0x8b, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x00, 
  0x00, 0x07, 0xe0, 0x00, 0x0c, 0x0a, 0x77, 0x38, 0x7d, 0x0b, 0x80, 0x00, 0x00, 0x00, 0x01, 0xc0, 
  0x00, 0x0e, 0x70, 0x00, 0x09, 0xdf, 0x5d, 0xe0, 0xcf, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 
  0x00, 0x38, 0x38, 0x00, 0x0d, 0xdf, 0x5d, 0xe0, 0xc5, 0x1b, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x30, 
  0x00, 0xf0, 0x18, 0x00, 0x0c, 0xf3, 0xcd, 0xe0, 0xcd, 0xbb, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x10, 
  0x01, 0xc0, 0x0c, 0x00, 0x03, 0xe3, 0xc9, 0xf8, 0xf8, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x07, 0x18, 
  0x07, 0x80, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x08, 
  0x0f, 0x80, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc1, 0x88, 
  0x1c, 0xc0, 0x3f, 0xe0, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x70, 0x8c, 
  0x38, 0x60, 0x7c, 0xf0, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x18, 0xc4, 
  0x3c, 0x31, 0xf1, 0x7c, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x08, 0x44, 
  0x27, 0x3b, 0xc4, 0xfe, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x0c, 0x44, 
  0x23, 0x9f, 0x13, 0xcf, 0x83, 0xdf, 0x0f, 0x3b, 0xef, 0xbe, 0x7f, 0xc7, 0xe1, 0xf7, 0xc4, 0x44, 
  0x21, 0xfc, 0x4f, 0x87, 0xc3, 0xff, 0x8f, 0xfb, 0xef, 0xff, 0xff, 0xcf, 0xf1, 0xff, 0xc4, 0x44, 
  0x20, 0x79, 0x3f, 0xcf, 0xc7, 0xff, 0xdf, 0xfb, 0xcf, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x00, 0x00, 
  0x30, 0x3c, 0xff, 0xfe, 0xc7, 0xff, 0xdf, 0xf7, 0xdf, 0xff, 0xff, 0xff, 0xfd, 0xff, 0x00, 0x00, 
  0x18, 0x0f, 0xf3, 0xfc, 0x47, 0xcf, 0xdf, 0xf7, 0xdf, 0x9f, 0x3e, 0x7c, 0x7d, 0xff, 0x00, 0x00, 
  0x0e, 0x07, 0xe1, 0xf8, 0x47, 0xcf, 0xdf, 0x07, 0xdf, 0x1f, 0x3e, 0xff, 0xff, 0xf0, 0x00, 0x00, 
  0x03, 0x01, 0xf3, 0xe0, 0x4f, 0xcf, 0xfe, 0x07, 0xdf, 0x1f, 0x7c, 0xff, 0xff, 0xe0, 0x00, 0x00, 
  0x01, 0xc0, 0x7f, 0x80, 0xcf, 0xcf, 0xfe, 0x0f, 0x9e, 0x1f, 0x7c, 0xff, 0xff, 0xe0, 0x00, 0x00, 
  0x00, 0x60, 0x3e, 0x01, 0x8f, 0x9f, 0xfe, 0x0f, 0xbe, 0x3e, 0x7c, 0xf0, 0x03, 0xe0, 0x00, 0x00, 
  0x00, 0x38, 0x0c, 0x07, 0x0f, 0x9f, 0xbe, 0x0f, 0xbe, 0x3e, 0x7c, 0xf8, 0xff, 0xc0, 0x00, 0x00, 
  0x00, 0x0c, 0x00, 0x0c, 0x0f, 0xff, 0xbc, 0x0f, 0xbe, 0x3e, 0x7f, 0xff, 0xf7, 0xc0, 0x00, 0x00, 
  0x00, 0x07, 0x00, 0x38, 0x1f, 0xff, 0x7c, 0x0f, 0x3e, 0x3e, 0x7f, 0xff, 0xf7, 0xc0, 0x00, 0x00, 
  0x00, 0x01, 0x80, 0xe0, 0x1f, 0xfe, 0x7c, 0x1f, 0x7c, 0x3c, 0x7f, 0x7f, 0xe7, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0xe1, 0x80, 0x1f, 0x7c, 0x7c, 0x1f, 0x7c, 0x7c, 0x3e, 0x3f, 0x87, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x3f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void oled_setup() {
  Wire.begin(OLED_SDA, OLED_SCL);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  #ifdef OLED_ROTATE
    display.setRotation(2);
  #endif

  oled_drawSplashScreen();
}

void oled_msg(String message) {
  oled_msg(message, 12);
}

void oled_msg(String message1, String message2) {
  oled_msg(message1 + "\n" + message2, 8);
}

void oled_msg(String message1, String message2, String message3) {
  oled_msg(message1 + "\n" + message2 + "\n" + message3, 4);
}

void oled_msg(String message1, String message2, String message3, String message4) {
  oled_msg(message1 + "\n" + message2 + "\n" + message3 + "\n" + message4, 0);
}

void oled_msg(String message, byte y) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, y);
  display.println(message);
  display.display();
  #ifdef OLED_INVERT
  display.invertDisplay(true);
  #endif
}

void oled_drawSplashScreen() {
  display.clearDisplay();
  display.drawBitmap(0, 0, splashScreenlogo, SCREEN_WIDTH, SCREEN_HEIGHT, 1);
  display.display();
}

#endif
