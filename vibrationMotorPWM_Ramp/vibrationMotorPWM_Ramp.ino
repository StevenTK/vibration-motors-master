void setup() {
  pinMode( 6 , OUTPUT);  // Must be a PWM pin
}

void loop() {
  
 // analogWrite( 6 , 153 );  // 60% duty cycle  
  for (int i=0; i<153; i++) {
    analogWrite(6, i);
    delay(10);
  }           // wait for 4s
 // delay(10);

}
