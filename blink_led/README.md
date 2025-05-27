# Hướng dẫn sử dụng dự án Blink LED với ESP32 và OLED SSD1315

## 1. Giới thiệu
Dự án này sử dụng ESP32 DevKit V1 để điều khiển LED và hiển thị thông tin lên màn hình OLED SSD1315 qua giao thức I2C. Code sử dụng framework Arduino và quản lý bằng PlatformIO.

## 2. Yêu cầu phần cứng
- ESP32 DevKit V1
- Màn hình OLED SSD1315 (I2C, địa chỉ 0x3C)
- Dây nối
- (Tùy chọn) LED ngoài nếu không dùng LED on-board

## 3. Kết nối phần cứng
- OLED:
  - SDA -> GPIO 21 (ESP32)
  - SCL -> GPIO 22 (ESP32)
  - VCC -> 3.3V
  - GND -> GND
- LED: sử dụng chân GPIO2 (LED on-board)

## 4. Cài đặt phần mềm
### a. Cài đặt PlatformIO
- Cài đặt [VSCode](https://code.visualstudio.com/)
- Cài đặt extension [PlatformIO IDE](https://platformio.org/install/ide?install=vscode)

### b. Tải mã nguồn
Clone hoặc copy thư mục dự án này về máy tính của bạn.

### c. Cài đặt thư viện
Các thư viện cần thiết đã được khai báo trong `platformio.ini`:
- Adafruit SSD1306
- Adafruit GFX Library

PlatformIO sẽ tự động cài đặt khi build lần đầu.

## 5. Build và nạp chương trình
1. Mở thư mục `blink_led` bằng VSCode với PlatformIO.
2. Kết nối ESP32 với máy tính qua cáp USB.
3. Nhấn nút **Build** (dấu check) để biên dịch.
4. Nhấn **Upload** (mũi tên phải) để nạp chương trình vào ESP32.

## 6. Chức năng chương trình
- Kết nối WiFi với SSID và mật khẩu đã khai báo trong code (`src/main.cpp`).
- Hiển thị "Hello ESP32!" lên màn hình OLED nếu khởi tạo thành công.
- Nháy LED on-board mỗi 1 giây.
- Nếu không tìm thấy OLED, LED sẽ nháy nhanh 20 lần và dừng.

## 7. Tùy chỉnh
- Để đổi WiFi, sửa biến `ssid` và `password` trong `src/main.cpp`.
- Có thể thay đổi chân LED bằng cách sửa giá trị `ledPin`.

## 8. Tham khảo
- [Tài liệu PlatformIO](https://docs.platformio.org/)
- [ESP32 Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
- [Adafruit SSD1306 library](https://github.com/adafruit/Adafruit_SSD1306)

---
Mọi thắc mắc vui lòng liên hệ tác giả dự án.
