/*
 * Program for Smart Blind Walking Stick Using Arduino and two Ultrasonic Sensors.
 * Code by ELECTRODUINO
 * Website: www.electroduino.com
 */
 
int trigpin1 = 8; // Defines Tirg pins of the Ultrasonic Sensor 1
int echopin1 = 7; // Defines Echo pins of the Ultrasonic Sensor 1
 
int trigpin2 = 10; // Defines Tirg pins of the Ultrasonic Sensor 2
int echopin2 = 9; // Defines Echo pins of the Ultrasonic Sensor 2
 
int BUZZpin = 3; // Defines BUZZER pins
int Vmotor = 2; // Defines Vibrating motor pins
 
void setup()
 {
  Serial.begin (9600);
  pinMode(trigpin1,OUTPUT); // Sets the trigPin1 as an Output
  pinMode(echopin1,INPUT);  // Sets the echoPin1 as an Input
  
  pinMode(trigpin2,OUTPUT); // Sets the trigPin1 as an Output
  pinMode(echopin2,INPUT);  // Sets the echoPin1 as an Input
     
  pinMode(BUZZpin,OUTPUT); // Sets the BUZZER as an Output
  pinMode(Vmotor,OUTPUT); // Sets the BUZZER as an Output
  
  }
 
  void loop()
  {
    // measure distane using ultrasonic sensor 1 and Print sensor deta in serial monitor
    long duration1, distance1;
    digitalWrite(trigpin1,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin1,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin1,LOW);
    duration1 = pulseIn(echopin1,HIGH);
    distance1 = (duration1/2) / 29.1;
    Serial.print("distance1:");
    Serial.println(distance1); // TO Print sensor deta in serial monitor
   // delay(500); // delay for clearly shown in serial monitor
 
    // measure distane using ultrasonic sensor 2 and Print sensor deta in serial monitor
    long duration2, distance2;
    digitalWrite(trigpin2,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin2,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin2,LOW);
    duration2 = pulseIn(echopin2,HIGH);
    distance2 = (duration2/2) / 29.1;
    Serial.print("distance2:");
    Serial.println(distance2); // TO Print sensor deta in serial monitor
   // delay(500); // delay for clearly shown in serial monitor
 
 
 
    //if any sensor senses distance less than 80 cm then the buzzer generates sound and the motor starts vibrating.
    if(distance1 <= 80 || distance2 <= 80 ) 
    {
      digitalWrite(BUZZpin,HIGH);
      delay(100);
      digitalWrite(BUZZpin,LOW);
      delay(100);
      digitalWrite(Vmotor,HIGH);
      delay(100);
      digitalWrite(Vmotor,LOW);
      delay(100);
     }
 
 //if any sensor senses distance less than 40 cm then the buzzer generates sound and the motor starts vibrating faster
    if(distance1 <= 40 || distance2 <= 40 ) 
    {
      digitalWrite(BUZZpin,HIGH);
      delay(50);
      digitalWrite(BUZZpin,LOW);
      delay(50);
      digitalWrite(Vmotor,HIGH);
      delay(50);
      digitalWrite(Vmotor,LOW);
      delay(50);
     }
   // else the buzzer generates sound after every 3 seconds for indicating the device is on         
    else 
     {
      digitalWrite(BUZZpin,LOW);
      digitalWrite(Vmotor,LOW);
      }
   } 
