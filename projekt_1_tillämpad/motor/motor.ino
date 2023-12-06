const int motorLeft = 3;
int motorRight = 5;
int sensorPin = 2;  // line detection sensor interface
int val;            // variable to store sensor reading

void setup() {
  // initialize digital pin RELAY_PIN as an output.
  pinMode (motorLeft, OUTPUT);
  pinMode(sensorPin,INPUT);  // define sensor as input  
  Serial.begin(9600);     // initialize serial communication with PC
}

// the loop function runs over and over again forever
void loop() {
  val = digitalRead(sensorPin); // read value from sensor
  
  if (val == LOW) { 
    Serial.println("Line detected");
    forward(); 
  } else { 
    Serial.println("Line NOT detected"); 
    digitalWrite (motorLeft, LOW);
  }
  delay(500);

}


void turnLeft() {

  digitalWrite(motorLeft, LOW);
  digitalWrite(motorRight,HIGH);
}

void turnRight() {
  digitalWrite(motorLeft, HIGH);
  digitalWrite(motorRight,LOW);
}

void forward() {
  digitalWrite(motorLeft, HIGH);
  digitalWrite(motorRight,HIGH);
}
