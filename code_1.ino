// CODE FOR COVID-360
//1.arduino nano to Sanitizer IR sensor
//2.arduino nano to mask dispensor another IR sensor
int IRSensorS = 12; // connect ir sensor for sani to arduino 12
int IRSensorM = 8; // connect ir sensor  for mask to arduino pin 8
int fla = A2; // Motor Driver 2 Pins IN1
int flb = A3; // Motor Driver 2 Pins IN2
int san = 5; // Motor Driver 2 Pins IN3
int san1 = 6; // Motor Driver 2 Pins IN4
int pwm = 9;

void setup() {
  Serial.begin(9600);
  pinMode(pwm, OUTPUT);
  pinMode(IRSensorM, INPUT);
  pinMode(fla, OUTPUT);  // Digital pin A2 set as output Pin
  pinMode(flb, OUTPUT);  // Digital pin A3 set as output Pin
    pinMode(IRSensorS, INPUT);
  pinMode(san, OUTPUT);  // Digital pin 10 set as output Pin
  pinMode(san1, OUTPUT);  // Digital pin 10 set as output Pin
  }

void loop() {
    while(1){
      delay(100);
      while(digitalRead ((IRSensorS) == HIGH)&&(IRSensorM) == HIGH);
      if (digitalRead (IRSensorS) == LOW) {
             Serial.println(120);
            digitalWrite( san1, HIGH);
        delay(200);//480
         digitalWrite( san1, LOW);
      while(digitalRead (IRSensorS) == LOW);
      }else if(digitalRead (IRSensorS) == HIGH){

      digitalWrite( san1, LOW);
      }
      if (digitalRead (IRSensorM) == LOW) {
        Serial.println(120);
        analogWrite(pwm, 140);
        delay(10);
        digitalWrite( fla, HIGH);
        digitalWrite( flb, LOW);
        delay(400);//480
      digitalWrite( fla, LOW);
      digitalWrite( flb, LOW);
      analogWrite(pwm, 255);
      while(digitalRead (IRSensorM) == LOW);
      delay(2000);
      }else if(digitalRead (IRSensorM) == HIGH){
        digitalWrite( fla, LOW);
      digitalWrite( flb, LOW);
      }
    }         
}
