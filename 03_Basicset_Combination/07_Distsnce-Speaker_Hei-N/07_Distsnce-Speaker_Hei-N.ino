const int trigPin = 3; //3:ConnectorA 4:ConnectorB
const int echoPin = 1; //1:ConnectorA 5:ConnectorB
const int spkrPin = 4; //3:ConnectorA 4:ConnectorB

float Duration = 0; //Received Interval Time
float Distance = 0; //Calculation results from Duration
#define RA0 110
#define TI0 124

#define DO1 131
#define _DO1 139
#define RE1 147
#define _RE1 156
#define MI1 165
#define FA1 175
#define SO1 196
#define RA1 220
#define TI1 247

#define DO 262
#define _DO 277
#define RE 294
#define _RE 311
#define MI 330
#define FA 349
#define _FA 370
#define SO 392
#define _SO 415
#define RA 440
#define _RA 466
#define TI 494

#define C5  523 // ド
#define D5  587 // レ
#define E5  659 // ミ
#define F5  698 // ファ
#define G5  784 // ソ
#define A5  880 // ラ
#define B5  988 // シ

#define C6  1047 // ド
#define D6  1175 // レ
#define E6  1319 // ミ
#define F6  1397 // ファ
#define G6  1568 // ソ
#define A6  1760 // ラ
#define B6  1976 // シ
#define C7  2094

int Prelude[] = {
  DO1, RE1, MI1, SO1, DO, RE, MI, SO, C5, D5, E5, G5, C6, D6, E6, C7, G6, E6, D6, C6, G5, E5, D5, C5, SO, MI, RE, DO, SO1, MI1, RE1,
  RA0, TI0, DO1, MI1, RA1, TI1, DO, MI, RA, TI, C5, E5, A5, B5, C6, E6, A6, E6, C6, B5, A5, E5, C5, TI, RA, MI, DO, TI1, RA1, MI1, DO1, TI0
};
int PnoteCount = sizeof(Prelude) / sizeof(Prelude[0]); 

void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
  ledcWriteTone(spkrPin, 0); // no sound
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

  //Look at the serial monitor
  Serial.print("Distance:");
  Serial.print(Distance);
  Serial.println("m");
  delay(500);

  bool Pisconpleted = playMusic(Prelude, PnoteCount);

  if(Pisconpleted == false){

    while(Distance <= 0.2){
      delay(500);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH); //Ultrasonic output
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      Duration = pulseIn(echoPin, HIGH); //Input from sensor
      Duration = Duration/2; //Half the round trip time
      Distance = Duration*340*100/100000000; //Set sonic speed to 340 m/s

    }
    delay(3000);
  }
  else{
    delay(5000);
  }
}


bool playMusic(int musicMelody[], int totalNotes){

  for(int thisNote = 0; thisNote < totalNotes; thisNote++){

    ledcWriteTone(spkrPin, musicMelody[thisNote]);

    for(int i = 0; i < 250; i = i + 10){
      delay(10);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH); //Ultrasonic output
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      Duration = pulseIn(echoPin, HIGH); //Input from sensor
      Duration = Duration/2; //Half the round trip time
      Distance = Duration*340*100/100000000; //Set sonic speed to 340 m/s
    
      if(Distance <= 0.2){
        ledcWriteTone(spkrPin, 0); 
        return false;

      }
    }
  }
  ledcWriteTone(spkrPin, 0); 
  return true;
}
  // if(musicNo == 0){
  // ledcWriteTone(spkrPin, 0); // no sound    
  // }
  // if(musicNo == 1){
  // playmusic();  //FF-Prelude
  // delay(1000);
  // musiNo = 2;
  // }
  // if(musicNo == 2){
  // doremi();
  // delay(1000);
  // musicNo = 3;
  // }
  // if(musicNo == 3){
  // melodychime();
  // delay(1000);
  // musicNo = 4;
  // }
  // if(musicNo == 4){
  // fryer();
  // delay(1000);
  // musicNo = 1;
  // }

