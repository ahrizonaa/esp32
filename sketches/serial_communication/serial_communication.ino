String input = "";
bool eol = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("ESP32 initialization completed!");
  Serial.println("Input characters:");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char inchar = Serial.read();
    input += inchar;
    if (inchar == '\n') { eol = true; }
  }
  if (eol) {
    Serial.printf("Data received:  %s \n", input);
    input = "";
    eol = false;
  }
}
