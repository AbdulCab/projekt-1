
/*
 Filnamn: lineTracking_robot.ino
 Författare: Abdulmannan Cabdalla
 datum: 2023-09-20
 Beskrivning: Det här programmet ska få motorer att åka fram när sensorerna har värdet LOW. När endast en av sensorerna är HIGH ska endast en av motorerna köra fram så att roboten kan svänga
 */



int motorLeft = 5; // länkar motorLeft variabeln till pin 5
int motorRight = 3; // länkar motorRight variabeln till pin 3
int sensorLeft = 2; // länkar variabeln till pin 2
int sensorRight = 9; 
int valL; // varibel för vänstra sensorn
int valR; // varibel för högra sensorn


void setup() {
  // put your setup code here, to run once:
  pinMode(motorLeft, OUTPUT); // kallar motorerna för outputs
  pinMode(motorRight, OUTPUT);
  
  pinMode(sensorLeft, INPUT); // kallar sensorerna för inputs
  pinMode(sensorRight, INPUT);
  Serial.begin(9600);  //sätter igång seriell monitorn

}

void loop() {
  // put your main code here, to run repeatedly:
  valL = digitalRead(sensorLeft);       // läser om sensorLeft har stadiet HIGH eller LOW
  valR = digitalRead(sensorRight);      // läser om sensorRight har stadiet HIGH eller LOW

  if (valL == LOW && valR == LOW) {     // villkor för att anropa funktionen forward()
    forward();
  }
  if (valL == LOW && valR == HIGH) {    // villkor för att anropa funktionen turnRight()
    turnRight();
  }
  if (valL == HIGH && valR == LOW){     // villkor för att anropa funktionen turnLeft()
    turnLeft();
  }
  if (valL == HIGH && valR == HIGH) {   // villkor för att anropa funktionen nothing()
    nothing();
  }
}


void turnLeft() {   // skapa funktion för att svänga vänster
  digitalWrite(motorLeft, LOW);
  digitalWrite(motorRight,HIGH);
}

void turnRight() {    // skapa funktion för att svänga höger
  digitalWrite(motorLeft, HIGH);
  digitalWrite(motorRight,LOW);
}

void forward() {      // skapa funktion för att köra rakt fram
  digitalWrite(motorLeft, HIGH);
  digitalWrite(motorRight,HIGH);
} 

void nothing() {       // skapa funktion för att stoppa
  digitalWrite(motorLeft, LOW);
  digitalWrite(motorRight,LOW);
}