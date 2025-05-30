#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <Wire.h>
#include <math.h> // Thư viện math để sử dụng hàm sin()

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1 // Dùng -1 nếu không có chân RESET
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// // Thay thông tin mạng của bạn ở đây
// const char *ssid         = "MVI";
// const char *password     = "Tech@2023";
// const int   ledPin       = 2;     // Chân LED trên ESP32
// bool        isConnectWifi= false; // Biến để kiểm tra kết nối WiFi

// bool isI2CDevicePresent(uint8_t address) {
//   Wire.beginTransmission(address);
//   return Wire.endTransmission() == 0;
// }

// bool initOLED() {
//   Wire.begin(21, 22); // SDA, SCL cho ESP32

//   const uint8_t oled_addr= 0x3C; // SSD1315 thường là 0x3C

//   if (!isI2CDevicePresent(oled_addr)) {
//     // Serial.println("Không tìm thấy OLED trên I2C!");
//     return false;
//   }

//   if (!display.begin(SSD1306_SWITCHCAPVCC, oled_addr)) {
//     // Serial.println("display.begin() thất bại!");
//     return false;
//   }

//   display.clearDisplay();
//   display.display();
//   Serial.println("OLED đã khởi tạo thành công!");
//   return true;
// }
// void showTextOLED(const String &text, uint8_t size= 1, int16_t x= 0, int16_t y= 0)
// {
//   display.clearDisplay();
//   display.setTextSize(size);
//   display.setTextColor(SSD1306_WHITE);
//   display.setCursor(x, y);
//   display.println(text);
//   display.display();
// }

// void showSmileyOLED() {
//   display.clearDisplay();
//   // Mắt trái
//   display.fillRect(40, 20, 12, 12, SSD1306_WHITE);
//   // Mắt phải
//   display.fillRect(76, 20, 12, 12, SSD1306_WHITE);
//   // Miệng (dùng các pixel tạo đường cong)
//   for (int x= 52; x <= 76; x++) {
//     int y= 48 + (int)(4 * sin((x - 52) * 3.14 / 24));
//     display.drawPixel(x, y, SSD1306_WHITE);
//   }
//   display.display();
// }

// bool connectWifi() {
//   Serial.begin(115200);
//   delay(1000);
//   // Bắt đầu kết nối WiFi
//   Serial.println("Dang ket noi WiFi...");
//   WiFi.begin(ssid, password);

//   // Chờ đến khi kết nối thành công
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   // Kết nối thành công
//   Serial.println("");
//   Serial.println("Da ket noi WiFi");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());
//   Serial.print("MAC Address: ");
//   Serial.println(WiFi.macAddress());

//   isConnectWifi= true; // Đặt biến kết nối WiFi là true
//   return isConnectWifi;
// }

// void setup() {
//   pinMode(ledPin, OUTPUT);
//   digitalWrite(ledPin, HIGH); // bat LED ban đầu
//   // if (connectWifi()) {
//   //   delay(1000); // Đợi 1 giây sau khi kết nối WiFi
//   // }
//   if (initOLED()) {
//     // showTextOLED("Hello ESP32!", 2); // size 2, vị trí (0,0)
//     showSmileyOLED(); // Hiển thị mặt cười
//   } else {
//     // Serial.println("Khong the khoi tao OLED");
//     int iOut= 0;
//     while (true) {
//       digitalWrite(ledPin, LOW);  // tat LED
//       delay(100);                 // Đợi 200 ms
//       digitalWrite(ledPin, HIGH); // bat LED
//       delay(100);
//       iOut+= 1;
//       if (iOut > 20) { // sau 20 lần thì thoát
//         // Serial.println("Khong the khoi tao OLED");
//         break;
//       }
//     }
//   }
// }
// void loop() {
//   digitalWrite(ledPin, LOW);  // tat LED
//   delay(1000);                // Đợi 1000 ms
//   digitalWrite(ledPin, HIGH); // bat LED
//   delay(1000);
// }

void sleep() {
  display.clearDisplay();
  // blink
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);

  // small mouth
  display.fillRect(48, 45, 32, 8, WHITE);
  display.fillCircle(48, 48, 3, WHITE);
  display.fillCircle(80, 48, 3, WHITE);

  display.display();
  delay(1000);
  display.clearDisplay();

  // yawn
  // blink
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);

  display.fillCircle(64, 50, 8, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  // blink
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);

  // small mouth
  display.fillRect(48, 45, 32, 8, WHITE);
  display.fillCircle(48, 48, 3, WHITE);
  display.fillCircle(80, 48, 3, WHITE);

  display.display();
  delay(1000);
  display.clearDisplay();
  // yawn
  // blink
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

void regEyes() { // Regular eyes with Blinking
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
  display.fillCircle(64, 50, 12, WHITE);   // full smile
  display.fillRect(0, 38, 128, 12, BLACK); // hide top half of smile

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
  display.fillCircle(64, 50, 12, WHITE);   // full smile
  display.fillRect(0, 38, 128, 12, BLACK); // hide top half of smile

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
  display.fillCircle(64, 50, 12, WHITE);   // full smile
  display.fillRect(0, 38, 128, 12, BLACK); // hide top half of smile

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

void carrotEyes() { // ^ shape eyes
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
  display.fillCircle(64, 50, 12, WHITE);   // full smile
  display.fillRect(0, 38, 128, 12, BLACK); // hide top half of smile

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
  display.fillCircle(64, 50, 12, WHITE);   // full smile
  display.fillRect(0, 38, 128, 12, BLACK); // hide top half of smile

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

void setup() {
  const uint8_t OLED_ADDRESS= 0x3C;
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(28, 20);
  display.println("STRAZZ");
  display.setCursor(35, 40);
  display.println("TUNED");
  display.display();
  delay(1000);
  display.clearDisplay();
  sleep();
  wakeUp();
}

void loop() {

  int randomNum= random(5);

  if (randomNum == 1) {
    regEyes();
    randomNum= random(5);
  }
  if (randomNum == 2) {
    heart();
    randomNum= random(5);
  }
  if (randomNum == 3) {
    carrotEyes();
    randomNum= random(5);
  }
  if (randomNum == 4) {
    sideEye();
    randomNum= random(5);
  }
  if (randomNum == 5) {
    sideEye();
    randomNum= random(5);
  }
}