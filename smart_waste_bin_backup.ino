#include <WiFi.h>
#include <WebServer.h>

#include "config.h"
#include "radar.h"
#include "filter.h"
#include "smart_logic.h"
#include "web.h"

WebServer server(80);

void setup()
{
    Serial.begin(115200);

    Serial.println();
    Serial.println("==============================");
    Serial.println("Smart Waste Bin V2.0");
    Serial.println("==============================");

    initRadar();

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting WiFi");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi Connected");

    Serial.print("IP: ");
    Serial.println(WiFi.localIP());

    initWeb(server);

    Serial.println("System Ready");
}

void loop()
{
    readRadar();

    updateSmartLogic();

    updateWeb(server);

    delay(300);
}