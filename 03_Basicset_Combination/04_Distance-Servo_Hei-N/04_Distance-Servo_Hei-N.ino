#include <ESP32Servo.h> //ESP32Servo by Kevin Harrington

const int trigPin = 3; //3:ConnectorA 4:ConnectorB
const int echoPin = 1; //1:ConnectorA 5:ConnectorB
const int motorPin = 4; //3:ConnectorA 4:ConnectorB
Servo myservo;


float Duration = 0; //Received Interval Time
float Distance = 0; //Calculation results from Duration
  
void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  myservo.attach(motorPin);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Ultrasonic output
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  Duration = pulseIn(echoPin, HIGH); //Input from sensor
  Duration = Duration/2; //Half the round trip time
  Distance = Duration*340*100/100000000; //Set sonic speed to 340 m/s

  if (Distance > 0.2) {
  Serial.println("CLOSE");
  delay(500);
  } else {
          // 0-90 right
    for(int angle = 0; angle <= 180; angle++) {                        
    myservo.write(angle);
    delay(15);
  }
  // 90-0  left 
  for(int angle = 180; angle >= 0; angle--) {                 
    myservo.write(angle);  
    delay(15);      
  }
  Serial.println("OPEN");
  delay(500);
  }


  //Look at the serial monitor
  Serial.print("Distance:");
  Serial.print(Distance);
  Serial.println("m");
  delay(500);
}
