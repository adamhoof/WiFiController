#pragma once

#include "WiFiClientSecure.h"
#include <time.h>

class WifiController
{
private:
    const char* hostname;
    const char* ssid;
    const char* password;

    void setTimeForCertValidation();

public:
    WifiController();

    void setCertificates(WiFiClientSecure& wiFiClientSecure, const char* ca_cert, const char* client_cert,
                         const char* client_key, bool autoSetTime);

    WifiController& setHostname(const char* hostname);

    WifiController& setSSID(const char* ssid);

    WifiController& setPassword(const char* password);

    void connect();

    void maintainConnection();

    void disconnect();
};
