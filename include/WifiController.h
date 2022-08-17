#pragma once

#include "WiFiClientSecure.h"
#include <time.h>

class WifiController
{
private:
    String hostname;
    String ssid;
    String password;

    void setTimeForCertValidation();

public:
    WifiController();

    void setCertificates(WiFiClientSecure& wiFiClientSecure, const char* ca_cert, const char* client_cert,
                         const char* client_key, bool autoSetTime);

    WifiController& setHostname(const String& hostname);

    WifiController& setSSID(const char* ssid);

    WifiController& setPassword(const char* password);

    void connect();

    void maintainConnection();

    void disconnect();
};
