const trig_pin = 12;
const echo_pin = 13;
float time = 0.0;
float distance = 0.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);

  digitalWrite(trig_pin, LOW); // Clear trig_pin

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
    serial.print("Distance: "+)distance+" cm\n"); // print the distance to the serial monitor

    
}