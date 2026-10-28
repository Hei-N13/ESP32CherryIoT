const int ruptPin = 3; //3:ConnectorA 4:ConnectorB
const int vibPin = 4; //3:ConnectorA 4:ConnectorB 10:Builtin

int ruptCount = 0;
 
void setup() {
  pinMode(ruptPin, INPUT);
  pinMode(vibPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if(digitalRead(ruptPin) == LOW){
    ruptCount++;
    ruptCount < 6;
  }
  if (ruptCount == 5) {
  Serial.println("商品5個通過");
  digitalWrite(vibPin, HIGH);
  delay(1000);
  digitalWrite(vibPin, LOW);
  delay(1000);
  ruptCount = 0;
  }
  delay(500);

}

