int sensorLeft = 2;// line detection sensor interface
int val1; // variable to store sensor reading
int sensorMiddle = 7;
int val2;
int sensorRight = 10;
int val3;

void setup() {
  pinMode(sensorLeft,INPUT);  // define sensor as input 
  pinMode(sensorMiddle,INPUT);  // define sensor as input 
  pinMode(sensorRight,INPUT);  // define sensor as input  
  Serial.begin(9600);     // initialize serial communication with PC
}
void loop() {
  val1 = digitalRead(sensorLeft); // read value from sensor
  val2 = digitalRead(sensorMiddle); // read value from sensor
  val3 = digitalRead(sensorRight); // read value from sensor

  if (val1 == LOW && val2 == HIGH && val3 == LOW) {
    forward();
  }
else if (val1 == HIGH && val2 == LOW && val3 == LOW) {
  turnRight();
}
else if (val1 == LOW && val2 == LOW && val3 == HIGH) {
  turnLeft();
}

}
