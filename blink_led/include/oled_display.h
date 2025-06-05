#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <Wire.h>
#include <math.h>

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1 // Dùng -1 nếu không có chân RESET

extern Adafruit_SSD1306 display;
extern const char      *ssid;
extern const char      *password;
extern const int        ledPin;
extern bool             isConnectWifi;

bool isI2CDevicePresent(uint8_t address);
bool initOLED();
void showTextOLED(const String &text, uint8_t size= 1, int16_t x= 0, int16_t y= 0);
void showSmileyOLED();
void sleep();
void wakeUp();
void regEyes();
void sideEye();
void heart();
void carrotEyes();
void drawHappyFace();
void drawSadFace();
void drawSurprisedFace();
void drawCuteFace();
void drawFaceBitmap();
void drawBitmapFromBin(const char *path, int x, int y, int w, int h);

#endif // OLED_DISPLAY_H
