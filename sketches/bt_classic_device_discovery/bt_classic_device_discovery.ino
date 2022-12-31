#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoWebsockets.h>
#include <ArduinoJson.h>
#include "WiFiCredentials.h"
#include "UUID.h"

using namespace websockets;

WebsocketsClient client;

StaticJsonDocument<256> payload;

UUID uuid;

byte mac[6];

void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected WiFi");

  WiFi.macAddress(mac);
  payload["mac_addr"] =  String(mac[0],HEX) + ":" + String(mac[1],HEX) + ":" + String(mac[2],HEX) + ":" + String(mac[3],HEX) + ":" + String(mac[4],HEX) + ":" + String(mac[5],HEX);
  payload["uuid"] = uuid.toCharArray();

  client.setCACert(ssl_ca_cert);
  bool connected = client.connect("wss://king-prawn-app-4cz2q.ondigitalocean.app:443");
  // client.setInsecure();
  // bool connected = client.connect("ws://192.168.1.129:8080");

  if (connected) {
    Serial.println("Connected WebSocket");
  } else {
    Serial.println("Not Connected WebSocket");
  }

}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
    payload["datapoint"] =  "Message from ESP32";
    char jsonStr[256];
    serializeJson(payload, jsonStr);
    client.send(jsonStr);
    Serial.println("Msg sent");
  }

  while (true)

  delay(5000);

}
