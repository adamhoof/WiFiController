#include <WifiController.h>

WifiController wifiController {};

const char wifiSSID[] = "your_ssid";
const char wifiPassword[] = "your_password";
const char hostname[] = "your_hostname";

void setup() {
    wifiController.setHostname(hostname).setSSID(wifiSSID).setPassword(wifiPassword);
    wifiController.connect();
}

void loop() {
    wifiController.maintainConnection();
}
