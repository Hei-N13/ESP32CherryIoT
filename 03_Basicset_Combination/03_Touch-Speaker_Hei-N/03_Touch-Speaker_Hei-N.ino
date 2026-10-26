const int touchPin = 3; //3:ConnectorA 4:ConnectorB
const int spkrPin = 4; //3:ConnectorA 4:ConnectorB
#define RA0 110
#define TI0 123.5

#define DO1 130.8
#define _DO1 138.59
#define RE1 146.8325
#define _RE1 155.5635
#define MI1 164.815
#define FA1 175
#define SO1 196
#define RA1 220
#define TI1 247

#define DO 261.6
#define _DO 277.18
#define RE 293.665
#define _RE 311.127
#define MI 329.63
#define FA 349.228
#define _FA 369.994
#define SO 391.995
#define _SO 415.305
#define RA 440
#define _RA 466.164
#define TI 493.883

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
void playmusic(){
  ledcWriteTone(spkrPin, DO1);
  delay(250);
  ledcWriteTone(spkrPin, RE1);
  delay(250);
  ledcWriteTone(spkrPin, MI1);
  delay(250);
  ledcWriteTone(spkrPin, SO1);
  delay(250);
  ledcWriteTone(spkrPin, DO);
  delay(250);
  ledcWriteTone(spkrPin, RE);
  delay(250);
  ledcWriteTone(spkrPin, MI);
  delay(250);
  ledcWriteTone(spkrPin, SO);
  delay(250);
  ledcWriteTone(spkrPin, C5);
  delay(250);
  ledcWriteTone(spkrPin, D5);
  delay(250);
  ledcWriteTone(spkrPin, E5);
  delay(250);
  ledcWriteTone(spkrPin, G5);
  delay(250);
  ledcWriteTone(spkrPin, C6);
  delay(250);
  ledcWriteTone(spkrPin, D6);
  delay(250);
  ledcWriteTone(spkrPin, E6);
  delay(250);
  ledcWriteTone(spkrPin, C7);
  delay(250);
  ledcWriteTone(spkrPin, G6);
  delay(250);
  ledcWriteTone(spkrPin, E6);
  delay(250);
  ledcWriteTone(spkrPin, D6);
  delay(250);
  ledcWriteTone(spkrPin, C6);
  delay(250); 
  ledcWriteTone(spkrPin, G5);
  delay(250);
  ledcWriteTone(spkrPin, E5);
  delay(250);
  ledcWriteTone(spkrPin, D5);
  delay(250);
  ledcWriteTone(spkrPin, C5);
  delay(250);
  ledcWriteTone(spkrPin, SO);
  delay(250);
  ledcWriteTone(spkrPin, MI);
  delay(250);
  ledcWriteTone(spkrPin, RE);
  delay(250);
  ledcWriteTone(spkrPin, DO);
  delay(250); 
  ledcWriteTone(spkrPin, SO1);
  delay(250);
  ledcWriteTone(spkrPin, MI1);
  delay(250);
  ledcWriteTone(spkrPin, RE1);
  delay(250);


  ledcWriteTone(spkrPin, RA0);
  delay(250);
  ledcWriteTone(spkrPin, TI0);
  delay(250);
  ledcWriteTone(spkrPin, DO1);
  delay(250);
  ledcWriteTone(spkrPin, MI1);
  delay(250);
  ledcWriteTone(spkrPin, RA1);
  delay(250);
  ledcWriteTone(spkrPin, TI1);
  delay(250);
  ledcWriteTone(spkrPin, DO);
  delay(250);
  ledcWriteTone(spkrPin, MI);
  delay(250);
  ledcWriteTone(spkrPin, RA);
  delay(250);
  ledcWriteTone(spkrPin, TI);
  delay(250);
  ledcWriteTone(spkrPin, C5);
  delay(250);
  ledcWriteTone(spkrPin, E5);
  delay(250);
  ledcWriteTone(spkrPin, A5);
  delay(250);
  ledcWriteTone(spkrPin, B5);
  delay(250);
  ledcWriteTone(spkrPin, C6);
  delay(250);
  ledcWriteTone(spkrPin, E6);
  delay(250);
  ledcWriteTone(spkrPin, A6);
  delay(250);
  ledcWriteTone(spkrPin, E6);
  delay(250);
  ledcWriteTone(spkrPin, C6);
  delay(250);
  ledcWriteTone(spkrPin, B5);
  delay(250);
  ledcWriteTone(spkrPin, A5);
  delay(250);
  ledcWriteTone(spkrPin, E5);
  delay(250);
  ledcWriteTone(spkrPin, C5);
  delay(250);
  ledcWriteTone(spkrPin, TI);
  delay(250);
  ledcWriteTone(spkrPin, RA);
  delay(250);
  ledcWriteTone(spkrPin, MI);
  delay(250);
  ledcWriteTone(spkrPin, DO);
  delay(250);
  ledcWriteTone(spkrPin, TI1);
  delay(250);
  ledcWriteTone(spkrPin, RA1);
  delay(250);
  ledcWriteTone(spkrPin, MI1);
  delay(250);
  ledcWriteTone(spkrPin, DO1);
  delay(250);
  ledcWriteTone(spkrPin, TI0);
  delay(250);
  
  ledcWriteTone(spkrPin, 0); // no sound
  delay(250);
}

void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)

}

void loop() {
  //Look at the serial monitor
  if (digitalRead(touchPin) == HIGH) {
    Serial.println("Touch!");
    playmusic();
    delay(3000);

    //delay(200);
  } else {
    Serial.println("...");
    //delay(200);
  }
  delay(250);
}