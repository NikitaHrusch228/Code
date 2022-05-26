#define REST 0
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
int tempo = 225;

int buzzer = 13;

const int melody[] PROGMEM = {

NOTE_F4, 4, NOTE_F4, 8, NOTE_F4, 8, NOTE_F4, 4, NOTE_F4, 8, NOTE_F4, 8,
NOTE_F4, 4, NOTE_F4, 4, NOTE_F4, 8, NOTE_F4, 8, NOTE_C5, 4,
NOTE_F4, 4, NOTE_F4, 8, NOTE_F4, 8, NOTE_AS4, 4, NOTE_F4, 8, NOTE_F4, 8,
NOTE_F4, 4, NOTE_F4, 4, NOTE_F4, 8, NOTE_F4, 8, NOTE_C5, 4,
NOTE_F3, 2, NOTE_GS3, 2, REST, 2, REST, 2,
NOTE_GS3, 2, NOTE_AS3, 2, REST, 2, REST, 2,
NOTE_CS4, 2, NOTE_C4, 2, REST, 2, REST, 2,
NOTE_C4, 2, NOTE_AS3, 2, REST, 2, REST, 2,
NOTE_F3, 2, NOTE_GS3, 2, REST, 2, REST, 2,
NOTE_GS3, 2, NOTE_AS3, 2, REST, 2, REST, 2,
NOTE_CS4, 2, NOTE_C4, 2, REST, 2, REST, 2,
NOTE_C4, 2, NOTE_AS3, 2, REST, 2, REST, 2,
NOTE_F3, 3, NOTE_C4, 3, NOTE_F4, 3, NOTE_F4, 3, NOTE_C4, 3, NOTE_F3, 3,
NOTE_F3, 3, NOTE_C4, 3, NOTE_F4, 3, NOTE_F4, 1,
REST, 4, NOTE_F3, 4, NOTE_C4, 4, NOTE_F4, 4, NOTE_F4, 3, NOTE_C4, 3, NOTE_F3, 3,
NOTE_F3, 3, NOTE_C4, 3, NOTE_F4, 3, NOTE_F4, 2, NOTE_C4, 2,
NOTE_F3, 3, NOTE_C4, 3, NOTE_F4, 3, NOTE_F4, 3, NOTE_C4, 3, NOTE_F3, 3,
NOTE_F3, 3, NOTE_C4, 3, NOTE_F4, 3, NOTE_F4, 1,
REST, 4, NOTE_F3, 4, NOTE_C4, 4, NOTE_F4, 4, NOTE_F4, 3, NOTE_C4, 3, NOTE_F3, 3,
NOTE_F3, 3, NOTE_C4, 3, NOTE_F4, 3, NOTE_F4, 2, NOTE_C4, 2,


};
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

#include <AFMotor.h>
#include <Servo.h>    // Подключаем библиотеку Servo    
AF_DCMotor motor1(3);
AF_DCMotor motor2(4);
Servo updown; //серво башни верх-вниз
Servo leftright; // серво башни лево-право
int val = 100;
int pos = 0;          // Создаем переменную
String state;
void setup() {
  updown.attach(9); // Указываем к какому порту подключен вывод сервопривода
  Serial.begin(9600);
  motor1.setSpeed(255);    // Начальная скорость вращения
  motor1.run(RELEASE);     // Останавливаем двигатель
  motor2.setSpeed(255);    // Начальная скорость вращения
  motor2.run(RELEASE);     // Останавливаем двигатель
  leftright.attach(10);
  pinMode(3, OUTPUT); 
  pinMode(11, OUTPUT);
}
 
 
void loop() 
{
  
    if (Serial.available() > 0) {
    state = Serial.readStringUntil('.');
    Serial.print("I received: ");
    Serial.println(state);
    delay(10);
    if (state == "A"){
      val = 200;
    }
    else if (state == "B"){
      val = 230;
    }
    else if (state == "C"){
      val = 255;
    } else if (state == "og"){
        digitalWrite(3, HIGH);   // зажигаем светодиод
        delay(400);             // 
        digitalWrite(3, LOW);    // выключаем светодиод
        delay(1000);
    }
   
    else if (state == "up") {
    if (pos < 178){
      pos = pos + 2; // Увеличиваем угол от 0 до 180
      updown.write(pos);  
    }         
    }
    else if (state == "dwn") {
      if (pos > 2){
      pos = pos - 2; 
      updown.write(pos);  
    }
    }
    else if (state == "hlft") {
      if (pos > 2){
      pos = pos - 2; 
      leftright.write(pos);  
    }
    }
    else if (state == "hrgt") {
      if (pos < 178){
      pos = pos + 2; // Увеличиваем угол от 0 до 180
      leftright.write(pos);  
    }    
    }
    

    
    else if (state == "fwd") {

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor1.setSpeed(val);
    motor2.setSpeed(val);
    delay(100);
    
    motor1.run(RELEASE);
    motor2.run(RELEASE);

    }
    else if (state == "bwd") {
    
    motor1.setSpeed(val);
    motor2.setSpeed(val);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    delay(100);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    
    }
    else if (state == "lft") {

    motor1.setSpeed(val);
    motor2.setSpeed(val);
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    delay(100);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    
    }
    else if (state == "rgt") {

    motor1.setSpeed(val);
    motor2.setSpeed(val);
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    delay(100);
    motor1.run(RELEASE);
    motor2.run(RELEASE);      
    
    }
    else if (state == "got") {
    
    }
    else if (state == "cel") {
    
    }
    else if (state == "song") {
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {


    divider = pgm_read_word_near(melody+thisNote + 1);
    if (divider > 0) {

      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {

      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }


    tone(buzzer, pgm_read_word_near(melody+thisNote), noteDuration * 0.5);

    delay(noteDuration);

    noTone(buzzer);
  }
    };
   }
}
