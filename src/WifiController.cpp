#include "WifiController.h"

WifiController::WifiController() = default;

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
    struct tm timeInfo{};
    gmtime_r(&now, &timeInfo);
}

void WifiController::setCertificates(WiFiClientSecure &wiFiClientSecure, const char* ca_cert, const char* client_cert, const char* client_key, bool autoSetTime)
{
    if (autoSetTime) {
        setTimeForCertValidation();
    }

    wiFiClientSecure.setCACert(ca_cert);
    wiFiClientSecure.setCertificate(client_cert);
    wiFiClientSecure.setPrivateKey(client_key);
}

WifiController& WifiController::setHostname(const char* hostname)
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
    tcpip_adapter_set_hostname(TCPIP_ADAPTER_IF_STA, hostname);

    WiFi.begin(ssid, password);
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
    }
}
