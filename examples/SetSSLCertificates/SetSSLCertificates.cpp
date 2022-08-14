#include <WifiController.h>
#include <pgmspace.h>

WifiController wifiController = WifiController();

//create an instance of WiFiClientSecure to be able to set certificates
WiFiClientSecure wiFiClientSecure = WiFiClientSecure();

const char wifiSSID[] = "your_ssid";
const char wifiPassword[] = "your_password";
const char hostname[] = "your_hostname";

//ALL the certificates are going to be stored in the memory of ESP -> do not forget to #include <pgmspace.h>
//BEGIN and END CERTIFICATE should be included in the certificate string
static const char CA_CERT[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIfdaho855fdsa8.........
-----END CERTIFICATE-----
)EOF";

//BEGIN and END CERTIFICATE should be included in the certificate string
static const char CLIENT_CERT[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIfdaho855fdsa8.........
-----END CERTIFICATE-----
)EOF";

//BEGIN and END RSA PRIVATE KEY should be included in the key string
static const char CLIENT_KEY[] PROGMEM = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
MIfdaho855fdsa8.........
-----END RSA PRIVATE KEY-----
)EOF";

void setup() {
    wifiController.setHostname(hostname).setSSID(wifiSSID).setPassword(wifiPassword);
    wifiController.connect();
    wifiController.setCertificates(&wiFiClientSecure, CA_CERT, CLIENT_CERT, CLIENT_KEY);
}

void loop() {
    wifiController.maintainConnection();
}
