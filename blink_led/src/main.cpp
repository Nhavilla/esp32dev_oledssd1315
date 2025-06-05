#include "oled_display.h"
#include "wifi_utils.h"

void setup() {
  const uint8_t OLED_ADDRESS= 0x3C;
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
  display.clearDisplay();
  // display.setTextSize(2);
  // display.setTextColor(WHITE);
  // display.setCursor(28, 20);
  // display.println("STRAZZ");
  // display.setCursor(35, 40);
  // display.println("TUNED");
  // display.display();
  // delay(1000);
  display.clearDisplay();
  sleep();
  // wakeUp();
}

void loop() {
  drawFaceBitmap();
  delay(2000);
  // int randomNum= random(5);
  // if (randomNum == 1) {
  // drawSadFace();
  // sleep(1);
  // randomNum= random(5);
  // }
  // if (randomNum == 2) {
  // heart();
  //   randomNum= random(5);
  // }
  // if (randomNum == 3) {
  // carrotEyes();
  //   randomNum= random(5);
  // }
  // if (randomNum == 4) {
  // sideEye();
  //   randomNum= random(5);
  // }
  // if (randomNum == 5) {
  // drawSurprisedFace();
  // sleep(1);
  //   randomNum= random(5);
  // }
  // if (randomNum == 0) {
  // showSmileyOLED();
  // sleep(1);
  //   randomNum= random(5);
  // }
}