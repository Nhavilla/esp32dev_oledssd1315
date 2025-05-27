#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <Wire.h>

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1 // Dùng -1 nếu không có chân RESET
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Thay thông tin mạng của bạn ở đây
const char *ssid         = "MVI";
const char *password     = "Tech@2023";
const int   ledPin       = 2;     // Chân LED trên ESP32
bool        isConnectWifi= false; // Biến để kiểm tra kết nối WiFi

bool isI2CDevicePresent(uint8_t address) {
  Wire.beginTransmission(address);
  return Wire.endTransmission() == 0;
}

bool initOLED() {
  Wire.begin(21, 22); // SDA, SCL cho ESP32

  const uint8_t oled_addr= 0x3C; // SSD1315 thường là 0x3C

  if (!isI2CDevicePresent(oled_addr)) {
    // Serial.println("Không tìm thấy OLED trên I2C!");
    return false;
  }

  if (!display.begin(SSD1306_SWITCHCAPVCC, oled_addr)) {
    // Serial.println("display.begin() thất bại!");
    return false;
  }

  display.clearDisplay();
  display.display();
  Serial.println("OLED đã khởi tạo thành công!");
  return true;
}
void showTextOLED(const String &text, uint8_t size= 1, int16_t x= 0, int16_t y= 0) {
  display.clearDisplay();
  display.setTextSize(size);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.println(text);
  display.display();
}

bool connectWifi() {
  Serial.begin(115200);
  delay(1000);
  // Bắt đầu kết nối WiFi
  Serial.println("Dang ket noi WiFi...");
  WiFi.begin(ssid, password);

  // Chờ đến khi kết nối thành công
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Kết nối thành công
  Serial.println("");
  Serial.println("Da ket noi WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  isConnectWifi= true; // Đặt biến kết nối WiFi là true
  return isConnectWifi;
}

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // bat LED ban đầu
  if (connectWifi()) {
    delay(1000); // Đợi 1 giây sau khi kết nối WiFi
  }
  if (initOLED()) {
    showTextOLED("Hello ESP32!", 2); // size 2, vị trí (0,0)
  } else {
    // Serial.println("Khong the khoi tao OLED");
    int iOut= 0;
    while (true) {
      digitalWrite(ledPin, LOW);  // tat LED
      delay(100);                 // Đợi 200 ms
      digitalWrite(ledPin, HIGH); // bat LED
      delay(100);
      iOut+= 1;
      if (iOut > 20) { // sau 20 lần thì thoát
        // Serial.println("Khong the khoi tao OLED");
        break;
      }
    }
  }
}
void loop() {
  digitalWrite(ledPin, LOW);  // tat LED
  delay(1000);                // Đợi 1000 ms
  digitalWrite(ledPin, HIGH); // bat LED
  delay(1000);
}
