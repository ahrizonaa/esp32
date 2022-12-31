void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  // if (WiFi.status() == WL_CONNECTED) {
  //   HTTPClient http;

  //   String serverPath = "https://esp32-http-post.vercel.app/api/hello";

  //   // Your Domain name with URL path or IP address with path
  //   http.begin(serverPath.c_str());

  //   // If you need Node-RED/server authentication, insert user and password below
  //   //http.setAuthorization("REPLAC_EWITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");

  //   // Send HTTP GET request
  //   int httpResponseCode = http.GET();

  //   if (httpResponseCode > 0) {
  //     Serial.print("HTTP Response code: ");
  //     Serial.println(httpResponseCode);
  //     String payload = http.getString();
  //     Serial.println(payload);
  //   } else {
  //     Serial.print("Error code: ");
  //     Serial.println(httpResponseCode);
  //   }
  //   // Free resources
  //   http.end();
  // } else {
  //   Serial.println("WiFi Disconnected");
  // }
  // while(true)

}
