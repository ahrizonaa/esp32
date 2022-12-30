#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
String buffer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("ESP32 BT");
  Serial.println("\nThe device started, now you can pair it with bluetooth.");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}
