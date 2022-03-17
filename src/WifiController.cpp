#include "WifiController.h"

WifiController::WifiController() = default;

WiFiClientSecure& WifiController::wiFiClientSecure()
{
    return wifiClientSecure;
}

void WifiController::setTimeForCertValidation()
{
    time_t now;
    configTime(-5 * 3600, 0, "pool.ntp.org", "time.nist.gov");
    now = time(nullptr);
    while (now < 1510592825) {
        delay(500);
        Serial.print(".");
        now = time(nullptr);
    }
    struct tm timeinfo;
    gmtime_r(&now, &timeinfo);
}

void WifiController::setCertificates(const char* ca_cert, const char* client_cert, const char* client_key)
{
    setTimeForCertValidation();

    wifiClientSecure.setCACert(ca_cert);
    wifiClientSecure.setCertificate(client_cert);
    wifiClientSecure.setPrivateKey(client_key);
}

WifiController& WifiController::setHostname(const String& hostname)
{
    this->hostname = hostname;
    return *this;
}

WifiController& WifiController::setSSID(const char* ssid)
{
    this->ssid = ssid;
    return *this;
}

WifiController& WifiController::setPassword(const char* password)
{
    this->password = password;
    return *this;
}

void WifiController::connect()
{
    WiFiClass::mode(WIFI_STA);

    WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);

    WiFi.setHostname(hostname.c_str());

    WiFi.begin(ssid.c_str(), password.c_str());

    Serial.println("Connecting to Wi-Fi");

    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        ESP.restart();
    }

    Serial.println("Wifi connected");
    Serial.println(WiFi.localIP());
}

void WifiController::disconnect()
{
    WiFi.disconnect();
}

void WifiController::maintainConnection()
{
    if (!WiFi.isConnected()) {
        disconnect();
        connect();
        delay(10);
    }
}
