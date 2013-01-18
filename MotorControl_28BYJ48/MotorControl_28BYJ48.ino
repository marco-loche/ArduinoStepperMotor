// This Arduino example demonstrates bidirectional operation of a
// 28BYJ-48, which is readily available on eBay, using a ULN2003
// interface board to drive the stepper. The 28BYJ-48 motor is a 4-
// phase, 8-beat motor, geared down by a factor of 68. One bipolar
// winding is on motor pins 1 & 3 and the other on motor pins 2 & 4.
// Refer to the manufacturer's documentation of Changzhou Fulling
// Motor Co., Ltd., among others. The step angle is 5.625/64 and the
// operating Frequency is 100pps. Current draw is 92mA. In this
// example, the speed and direction of the stepper motor is determined
// by adjusting a 1k-ohm potentiometer connected to Arduino pin A2.
// When the potentiometer is rotated fully counterclockwise, the motor
// will rotate at full counterclockwise speed. As the potentiometer is
// rotated clockwise, the motor will continue to slow down until is
// reaches its minimum speed at the the potentiometer's midpoint value .
// Once the potentiometer crosses its midpoint, the motor will reverse
// direction. As the potentiometer is rotated further clockwise, the speed
// of the motor will increase until it reaches its full clockwise rotation
// speed when the potentiometer has been rotated fully clockwise.
////////////////////////////////////////////////

//declare variables for the motor pins
int motorPin1 = 8; // Blue - 28BYJ48 pin 1
int motorPin2 = 9; // Pink - 28BYJ48 pin 2
int motorPin3 = 10; // Yellow - 28BYJ48 pin 3
int motorPin4 = 11; // Orange - 28BYJ48 pin 4
// Red - 28BYJ48 pin 5 (VCC)

int invMotorSpeed = 0; //variable to set stepper speed
int potPin = 2; //potentiometer connected to A2
int potValue = 0; //variable to read A0 input

//////////////////////////////////////////////////////////////////////////////
void setup() {
//declare the motor pins as outputs
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
Serial.begin(9600);
}

//////////////////////////////////////////////////////////////////////////////
void loop(){

potValue = analogRead(potPin); // read the value of the potentiometer
Serial.println(potValue); // View full range from 0 - 1024 in Serial Monitor
if (potValue < 535){ // if potentiometer reads 0 to 535 do this
invMotorSpeed = (potValue/10 + 5); //scale potValue to be useful for motor
clockwise(); //go to the ccw rotation function
}
else { //value of the potentiometer is 512 - 1024
invMotorSpeed = ((1024-potValue)/10 + 5); //scale potValue for motor speed
counterclockwise(); //go the the cw rotation function
}
}

//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)

void counterclockwise (){
// 1
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(invMotorSpeed);
// 2
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay (invMotorSpeed);
// 3
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(invMotorSpeed);
// 4
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(invMotorSpeed);
// 5
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(invMotorSpeed);
// 6
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, HIGH);
delay (invMotorSpeed);
// 7
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(invMotorSpeed);
// 8
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(invMotorSpeed);
}

//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 4 to 1
//delay "invMotorSpeed" between each pin setting (to determine speed)

void clockwise(){
// 1
digitalWrite(motorPin4, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin1, LOW);
delay(invMotorSpeed);
// 2
digitalWrite(motorPin4, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin1, LOW);
delay (invMotorSpeed);
// 3
digitalWrite(motorPin4, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin1, LOW);
delay(invMotorSpeed);
// 4
digitalWrite(motorPin4, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin1, LOW);
delay(invMotorSpeed);
// 5
digitalWrite(motorPin4, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin1, LOW);
delay(invMotorSpeed);
// 6
digitalWrite(motorPin4, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin1, HIGH);
delay (invMotorSpeed);
// 7
digitalWrite(motorPin4, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin1, HIGH);
delay(invMotorSpeed);
// 8
digitalWrite(motorPin4, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin1, HIGH);
delay(invMotorSpeed);
}
