#include "oled_display.h"
#include "wifi_utils.h"
#include <FS.h>
#include <SPIFFS.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
const int        ledPin= 2;

bool isI2CDevicePresent(uint8_t address) {
  Wire.beginTransmission(address);
  return Wire.endTransmission() == 0;
}

bool initOLED() {
  Wire.begin(21, 22);
  const uint8_t oled_addr= 0x3C;
  if (!isI2CDevicePresent(oled_addr)) {
    return false;
  }
  if (!display.begin(SSD1306_SWITCHCAPVCC, oled_addr)) {
    return false;
  }
  display.clearDisplay();
  display.display();
  Serial.println("OLED đã khởi tạo thành công!");
  return true;
}

void showTextOLED(const String &text, uint8_t size, int16_t x, int16_t y) {
  display.clearDisplay();
  display.setTextSize(size);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.println(text);
  display.display();
}

void showSmileyOLED() {
  display.clearDisplay();
  display.fillRect(40, 20, 12, 12, SSD1306_WHITE);
  display.fillRect(76, 20, 12, 12, SSD1306_WHITE);
  for (int x= 52; x <= 76; x++) {
    int y= 48 + (int)(4 * sin((x - 52) * 3.14 / 24));
    display.drawPixel(x, y, SSD1306_WHITE);
  }
  display.display();
}

void sleep() {
  display.clearDisplay();
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);
  display.fillRect(48, 45, 32, 8, WHITE);
  display.fillCircle(48, 48, 3, WHITE);
  display.fillCircle(80, 48, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);
  display.fillCircle(64, 50, 8, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);
  display.fillRect(48, 45, 32, 8, WHITE);
  display.fillCircle(48, 48, 3, WHITE);
  display.fillCircle(80, 48, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);
  display.fillCircle(64, 50, 8, WHITE);
  display.display();
  delay(1000);
}

void wakeUp() {
  display.clearDisplay();
  // blink
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // left wink
  display.fillCircle(46, 32, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // right wink
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillCircle(80, 32, 8, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // eyes
  display.clearDisplay();
  display.fillCircle(48, 32, 8, WHITE);
  display.fillCircle(80, 32, 8, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  display.fillRect(36, 28, 20, 4, WHITE);
  display.fillRect(76, 28, 20, 4, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(50);
  // eyes
  display.clearDisplay();
  display.fillCircle(48, 32, 8, WHITE);
  display.fillCircle(80, 32, 8, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  display.fillRect(44, 28, 10, 4, WHITE);
  display.fillRect(76, 28, 10, 4, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(50);
}

void regEyes() {
  // eyes
  display.clearDisplay();
  display.fillCircle(48, 32, 8, WHITE);
  display.fillCircle(80, 32, 8, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  display.fillRect(44, 28, 10, 4, WHITE);
  display.fillRect(76, 28, 10, 4, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(100);
  // open
  display.clearDisplay();
  display.fillCircle(48, 32, 8, WHITE);
  display.fillCircle(80, 32, 8, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  // blink
  display.fillRect(44, 28, 10, 4, WHITE);
  display.fillRect(76, 28, 10, 4, WHITE);
  display.display();
  delay(100);
}

void sideEye() {
  // eyes
  display.clearDisplay();
  display.fillCircle(48, 32, 8, WHITE);
  display.fillCircle(80, 32, 8, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  display.fillRect(32, 28, 10, 4, WHITE);
  display.fillRect(96, 28, 10, 4, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(100);
  display.clearDisplay();
  // side eye
  display.fillCircle(32, 32, 8, WHITE);
  display.fillCircle(96, 32, 8, WHITE);
  // mouth
  display.fillRect(32, 55, 64, 8, WHITE);
  display.fillCircle(32, 58, 3, WHITE);
  display.fillCircle(96, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  display.fillRect(32, 28, 10, 4, WHITE);
  display.fillRect(96, 28, 10, 4, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(100);
  display.clearDisplay();
  // side eye
  display.fillCircle(32, 32, 8, WHITE);
  display.fillCircle(96, 32, 8, WHITE);
  // mouth
  display.fillRect(32, 55, 64, 8, WHITE);
  display.fillCircle(32, 58, 3, WHITE);
  display.fillCircle(96, 58, 3, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  display.fillRect(32, 28, 10, 4, WHITE);
  display.fillRect(96, 28, 10, 4, WHITE);
  // small mouth
  display.fillRect(48, 55, 32, 8, WHITE);
  display.fillCircle(48, 58, 3, WHITE);
  display.fillCircle(80, 58, 3, WHITE);
  display.display();
  delay(100);
  display.clearDisplay();
}

void heart() {
  display.clearDisplay();
  int x1     = 44;
  int y1     = 27;
  int radius1= 10;
  // Draw the left heart
  display.fillTriangle(x1 - radius1, y1, x1, y1 + radius1, x1 + radius1, y1, WHITE);
  display.fillCircle(x1 - 5, y1, 5.5, WHITE);
  display.fillCircle(x1 + 5, y1, 5.5, WHITE);
  int x2     = 84;
  int y2     = 27;
  int radius2= 10;
  // Draw the right heart
  display.fillTriangle(x2 - radius2, y2, x2, y2 + radius2, x2 + radius2, y2, WHITE);
  display.fillCircle(x2 - 5, y2, 5.5, WHITE);
  display.fillCircle(x2 + 5, y2, 5.5, WHITE);
  // smile
  display.fillCircle(64, 50, 12, WHITE);
  display.fillRect(0, 38, 128, 12, BLACK);
  display.display();
  delay(1000);
  // blink
  display.clearDisplay();
  // smallest mouth
  display.fillRect(54, 54, 22, 4, WHITE);
  display.fillRect(44, 28, 10, 4, WHITE);
  display.fillRect(76, 28, 10, 4, WHITE);
  display.display();
  delay(100);
  display.clearDisplay();
  // smile
  display.fillCircle(64, 50, 12, WHITE);
  display.fillRect(0, 38, 128, 12, BLACK);
  // Draw the left heart
  display.fillTriangle(x1 - radius1, y1, x1, y1 + radius1, x1 + radius1, y1, WHITE);
  display.fillCircle(x1 - 5, y1, 5.5, WHITE);
  display.fillCircle(x1 + 5, y1, 5.5, WHITE);
  // Draw the right heart
  display.fillTriangle(x2 - radius2, y2, x2, y2 + radius2, x2 + radius2, y2, WHITE);
  display.fillCircle(x2 - 5, y2, 5.5, WHITE);
  display.fillCircle(x2 + 5, y2, 5.5, WHITE);
  display.display();
  delay(1000);
  // blink
  display.clearDisplay();
  display.fillRect(44, 28, 10, 4, WHITE);
  display.fillRect(76, 28, 10, 4, WHITE);
  // smallest mouth
  display.fillRect(54, 54, 22, 4, WHITE);
  display.display();
  delay(100);
  display.clearDisplay();
  // Draw the left heart
  display.fillTriangle(x1 - radius1, y1, x1, y1 + radius1, x1 + radius1, y1, WHITE);
  display.fillCircle(x1 - 5, y1, 5.5, WHITE);
  display.fillCircle(x1 + 5, y1, 5.5, WHITE);
  // Draw the right heart
  display.fillTriangle(x2 - radius2, y2, x2, y2 + radius2, x2 + radius2, y2, WHITE);
  display.fillCircle(x2 - 5, y2, 5.5, WHITE);
  display.fillCircle(x2 + 5, y2, 5.5, WHITE);
  // smile
  display.fillCircle(64, 50, 12, WHITE);
  display.fillRect(0, 38, 128, 12, BLACK);
  display.display();
  delay(1000);
  // blink
  display.clearDisplay();
  display.clearDisplay();
  display.fillRect(44, 28, 10, 4, WHITE);
  display.fillRect(76, 28, 10, 4, WHITE);
  // smallest mouth
  display.fillRect(54, 54, 22, 4, WHITE);
  display.display();
  delay(100);
  display.clearDisplay();
}

void carrotEyes() {
  display.clearDisplay();
  int centerX   = 42;
  int centerY   = 32;
  int lineLength= 10;
  // Draw the left ^ symbol
  display.drawLine(
      centerX - lineLength, centerY + lineLength, centerX, centerY - lineLength,
      WHITE);
  display.drawLine(
      centerX, centerY - lineLength, centerX + lineLength, centerY + lineLength,
      WHITE);
  int centerXl= 90;
  int centerYl= 32;
  // Draw the right ^ symbol
  display.drawLine(
      centerXl - lineLength, centerYl + lineLength, centerXl, centerYl - lineLength,
      WHITE);
  display.drawLine(
      centerXl, centerYl - lineLength, centerXl + lineLength, centerYl + lineLength,
      WHITE);
  // smile
  display.fillCircle(64, 50, 12, WHITE);
  display.fillRect(0, 38, 128, 12, BLACK);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  // smallest mouth
  display.fillRect(54, 54, 22, 4, WHITE);
  display.fillRect(38, 32, 10, 4, WHITE);
  display.fillRect(84, 32, 10, 4, WHITE);
  display.display();
  delay(50);
  display.clearDisplay();
  // Draw the left ^ symbol
  display.drawLine(
      centerX - lineLength, centerY + lineLength, centerX, centerY - lineLength,
      WHITE);
  display.drawLine(
      centerX, centerY - lineLength, centerX + lineLength, centerY + lineLength,
      WHITE);
  // Draw the right ^ symbol
  display.drawLine(
      centerXl - lineLength, centerYl + lineLength, centerXl, centerYl - lineLength,
      WHITE);
  display.drawLine(
      centerXl, centerYl - lineLength, centerXl + lineLength, centerYl + lineLength,
      WHITE);
  // smile
  display.fillCircle(64, 50, 12, WHITE);
  display.fillRect(0, 38, 128, 12, BLACK);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  // smallest mouth
  display.fillRect(54, 54, 22, 4, WHITE);
  display.fillRect(38, 32, 10, 4, WHITE);
  display.fillRect(84, 32, 10, 4, WHITE);
  display.display();
  delay(100);
  display.clearDisplay();
}

void drawHappyFace() {
  display.clearDisplay();
  // Eyes
  display.fillCircle(44, 28, 8, SSD1306_WHITE);
  display.fillCircle(84, 28, 8, SSD1306_WHITE);
  // Smile (approximate arc)
  int cx= 64, cy= 48, r= 20;
  for (int angle= 30; angle <= 150; angle+= 2) {
    float rad= angle * 3.14159 / 180.0;
    int   x  = cx + r * cos(rad);
    int   y  = cy + r * sin(rad);
    display.drawPixel(x, y, SSD1306_WHITE);
  }
  display.display();
}

void drawSadFace() {
  display.clearDisplay();
  // Eyes
  display.fillCircle(44, 28, 8, SSD1306_WHITE);
  display.fillCircle(84, 28, 8, SSD1306_WHITE);
  // Sad mouth (approximate arc)
  int cx= 64, cy= 60, r= 16;
  for (int angle= 210; angle <= 330; angle+= 2) {
    float rad= angle * 3.14159 / 180.0;
    int   x  = cx + r * cos(rad);
    int   y  = cy + r * sin(rad);
    display.drawPixel(x, y, SSD1306_WHITE);
  }
  display.display();
}

void drawSurprisedFace() {
  display.clearDisplay();
  // Eyes
  display.fillCircle(44, 28, 8, SSD1306_WHITE);
  display.fillCircle(84, 28, 8, SSD1306_WHITE);
  // Surprised mouth (circle)
  display.drawCircle(64, 48, 8, SSD1306_WHITE);
  display.display();
}

void drawCuteFace() {
  display.clearDisplay();
  // Mắt trái: hình chữ nhật bo góc, hơi nghiêng, to, sát giữa
  for (int i= 0; i < 8; ++i) {
    display.fillRoundRect(36 + i, 28 + i / 2, 20, 18, 6, SSD1306_WHITE);
  }
  // Mắt phải: hình chữ nhật bo góc, hơi nghiêng, to, sát giữa
  for (int i= 0; i < 8; ++i) {
    display.fillRoundRect(72 - i, 28 + i / 2, 20, 18, 6, SSD1306_WHITE);
  }
  // Miệng: cong dày, nhỏ, bo tròn hai đầu
  int cx= 64, cy= 54, r= 10;
  for (int thick= 0; thick < 6; ++thick) {
    for (int angle= 40; angle <= 140; angle+= 2) {
      float rad= angle * 3.14159 / 180.0;
      int   x  = cx + (r - thick / 2) * cos(rad);
      int   y  = cy + (r / 2 - thick / 3) * sin(rad) + 4;
      display.drawPixel(x, y, SSD1306_WHITE);
    }
  }
  // Bo tròn hai đầu miệng
  display.fillCircle(cx - 7, cy + 7, 3, SSD1306_WHITE);
  display.fillCircle(cx + 7, cy + 7, 3, SSD1306_WHITE);
  display.display();
}

// Bitmap mặt từ ảnh mẫu (ví dụ 64x48)
const unsigned char epd_bitmap_Screenshot_from_2025_06_04_22_47_42[]= {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0xff, 0xff,
    0xff, 0xfe, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x01,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff,
    0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00,
    0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfe, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0,
    0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x0f,
    0xff, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,
    0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf8, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00,
    0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff,
    0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
    0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00,
    0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff,
    0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00,
    0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0,
    0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x1f,
    0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0x00, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00,
    0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff,
    0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
    0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00,
    0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff,
    0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00,
    0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xf8, 0x3f, 0xf0,
    0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x0f,
    0xf8, 0x1f, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x00, 0x00, 0x1f, 0xf0, 0x0f, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xf0, 0x0f, 0xf8, 0x00, 0x00, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x3f, 0xe0, 0x0f, 0xfc, 0x00,
    0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xe0,
    0x0f, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
    0x00, 0xff, 0xe0, 0x0f, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x01, 0xff, 0xe0, 0x0f, 0xff, 0x80, 0x07, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x0f, 0xff, 0xe0, 0x0f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

void drawFaceBitmap() {
  display.clearDisplay();

  display.drawBitmap(
      0,                                                       // x: căn giữa
      0,                                                       // y: căn giữa
      epd_bitmap_Screenshot_from_2025_06_04_22_47_42, 128, 64, // width, height
      SSD1306_WHITE);
  display.display();
}
