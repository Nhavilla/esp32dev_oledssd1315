#include "wifi_utils.h"

const char *ssid = "MVI";
const char *password = "Tech@2023";
bool isConnectWifi = false;

bool connectWifi() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Dang ket noi WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Da ket noi WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
  isConnectWifi = true;
  return isConnectWifi;
}
