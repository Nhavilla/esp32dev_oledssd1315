#ifndef WIFI_UTILS_H
#define WIFI_UTILS_H

#include <WiFi.h>

extern const char *ssid;
extern const char *password;
extern bool isConnectWifi;

bool connectWifi();

#endif // WIFI_UTILS_H
