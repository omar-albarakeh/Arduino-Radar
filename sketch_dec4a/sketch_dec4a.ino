#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;

const int redLED = 8;  
const int greenLED = 9; 

long duration;
int distance;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);  
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);
  myServo.attach(12); 
}

void loop() {
  for (int i = 15; i <= 165; i++) {  
    myServo.write(i);
    delay(30);
    distance = calculateDistance(); 
    
    Serial.print(i); 
    Serial.print(","); 
    Serial.print(distance); 
    Serial.print("."); 
    
    controlLEDs(distance); 
  }


  for (int i = 165; i > 15; i--) {  
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    
    controlLEDs(distance); 
  }
}

int calculateDistance() { 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  

  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  return distance;
}

void controlLEDs(int distance) {
  if (distance < 30) { 
       digitalWrite(redLED, LOW);   
    digitalWrite(greenLED, HIGH);
   
  } else { 
  
     digitalWrite(redLED, HIGH);  
    digitalWrite(greenLED, LOW); 
  }
}
