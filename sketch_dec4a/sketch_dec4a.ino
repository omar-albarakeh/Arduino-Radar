void setup() {
  // put your setup code here, to run once:

}

void loop() {
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
