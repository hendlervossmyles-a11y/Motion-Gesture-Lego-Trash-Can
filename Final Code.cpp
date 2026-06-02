#include <Arduino.h>
#include <Servo.h>

Servo myservo;
int pos = 0;

const int trig_pin = 12;
const int echo_pin = 13;
float time = 0.0;
float distance = 0.0;
float inital_distance = 0.0;
bool isOpen = false;

void setup() {
  // put your setup code here, to run once:
  myservo.write(0); // set inital postition
  myservo.attach(2); //Using Digital Pin 2 for the servo motor

  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);

  digitalWrite(trig_pin, LOW); // Clear trig_pin

  inital_distance = readInitalDistance(); // Read the initial distance from the sensor

  Serial.begin(9600);
  
}

void loop() {
    // Main reading loop
    digitalWrite(trig_pin, LOW); // clear trig_pin
    
    delayMicroseconds(2); // wait for 2 microseconds
    
    digitalWrite(trig_pin, HIGH); // set trig_pin high
    
    delayMicroseconds(10); // wait for 10 microseconds
    
    digitalWrite(trig_pin, LOW); // clear trig_pin again

    time = pulseIn(echo_pin, HIGH); // read the echo_pin and store the time it was high
    distance = (time * 0.0343) / 2; // calculate distance in cm
    Serial.print("Distance: "); // print the distance to the serial monitor
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < (inital_distance / 2)) {
    if (isOpen == false) { 
      Serial.println("Object detected! Moving servo...");
      moveServo();   // This handles the open, the 3-second pause, and the close
      isOpen = true; // Mark the door as "used" for this object
    }
  } 
  // STEP 2: If the distance goes back to normal, reset isOpen to false
  else {
    isOpen = false; 
  }

  delay(60); 
}

float readInitalDistance() {
  // Function to read the initial distance from the sensor
  digitalWrite(trig_pin, LOW); // clear trig_pin
  
  delayMicroseconds(2); // wait for 2 microseconds
  
  digitalWrite(trig_pin, HIGH); // set trig_pin high
  
  delayMicroseconds(10); // wait for 10 microseconds
  
  digitalWrite(trig_pin, LOW); // clear trig_pin again

  time = pulseIn(echo_pin, HIGH); // read the echo_pin and store the time it was high
  distance = (time * 0.0343) / 2; // calculate distance in cm
  return distance; // return the calculated distance
}

void moveServo() {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(3000); // Wait for 3 second at the end position
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}