const int ledPin = 3; //3:ConnectorA 4:ConnectorB 10:Builtin

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); //ON
  delay(1000); //1.0sec
  digitalWrite(ledPin, LOW); //OFF
  delay(1000); //1.0sec
}