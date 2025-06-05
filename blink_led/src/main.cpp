#include "daichi_intro.h"
#include "oled_display.h"
#include "wifi_utils.h"

void setup() {
  const uint8_t OLED_ADDRESS= 0x3C;
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
  display.clearDisplay();
  sleep();
}
void playGIF(const AnimatedGIF *gif) {
  for (uint8_t frame= 0; frame < gif->frame_count; frame++) {
    display.clearDisplay();

    // Hiển thị khung hình hiện tại với màu đảo ngược
    for (uint16_t y= 0; y < gif->height; y++) {
      for (uint16_t x= 0; x < gif->width; x++) {
        uint16_t byteIndex= y * (((gif->width + 7) / 8)) + (x / 8);
        uint8_t  bitIndex = 7 - (x % 8);
        // Đảo ngược màu: pixel trắng thành đen, đen thành trắng
        if (!(gif->frames[frame][byteIndex] & (1 << bitIndex))) {
          display.drawPixel(x, y, WHITE);
        }
      }
    }

    display.display();
    delay(gif->delays[frame]);
  }
}

void loop() {
  // drawFaceBitmap();
  // delay(2000);
  playGIF(&daichi_intro_gif);
}