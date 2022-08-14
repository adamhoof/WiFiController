#include <WifiController.h>

WifiController wifiController = WifiController();
WiFiClientSecure wiFiClientSecure = WiFiClientSecure();

const char wifiSSID[] = "your_ssid";
const char wifiPassword[] = "your_password";
const char hostname[] = "your_hostname";

void setup() {
    wifiController.setHostname(hostname).setSSID(wifiSSID).setPassword(wifiPassword);
    wifiController.connect();
    wifiController.setCertificates(&wiFiClientSecure, CA_CERT, CLIENT_CERT, CLIENT_KEY); //look into certificates.h to see the certificate format
}

void loop() {
    wifiController.maintainConnection();
}
