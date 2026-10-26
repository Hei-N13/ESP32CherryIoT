const int ruptPin = 3; //3:ConnectorA 4:ConnectorB
const int vibPin = 4; //3:ConnectorA 4:ConnectorB 10:Builtin

int ruptState = 0;
 
void setup() {
  pinMode(ruptPin, INPUT);
  pinMode(vibPin, OUTPUT);
  attachInterrupt(ruptPin, vibration, FALLING);
}

void loop() {
  if (ruptState == 5) {
  //Serial.println("Interrupt!");
  digitalWrite(vibPin, HIGH);
  delay(1000);
  digitalWrite(vibPin, LOW);
  delay(1000);
  ruptState = 0;
  }
  delay(500);

  //digitalWrite(vibPin, HIGH);
}

void vibration(){
  delay(10);
  ruptState = ruptState + 1;
  ruptState < 6;
}