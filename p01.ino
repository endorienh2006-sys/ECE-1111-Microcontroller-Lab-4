// file: p01.ino
//
// revision history:
//   20260918: removed redundant arduino header to resolve linkage conflict
//

// define global hardware pin constants
//
const int SENSOR_PIN = A0;
const int RED_PIN = 2;
const int GREEN_PIN = 3;
const int BLUE_PIN = 4;

// define baud rate constant
//
const long BAUD_RATE = 9600;

// setup hardware peripherals and interfaces
//
void setup() {

  // configure indicator pins as digital outputs
  //
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // initialize serial communication
  //
  Serial.begin(BAUD_RATE);
}

// primary execution loop
//
void loop() {

  // read raw analog voltage count (0 - 1023) from sensor
  //
  int sensor_val = analogRead(SENSOR_PIN);

  // convert 10-bit adc count to voltage (0.0v - 5.0v)
  //
  float voltage = sensor_val * (5.0 / 1023.0);

  // convert voltage to celsius (10 mv/c with 500 mv offset at 0 c)
  //
  float temp_c = (voltage - 0.5) * 100.0;

  // convert celsius temperature to fahrenheit
  //
  float temp_f = (temp_c * 9.0 / 5.0) + 32.0;

  // output temperature reading to serial monitor
  //
  Serial.print("Temp: ");
  Serial.print(temp_f);
  Serial.println(" F");

  // evaluate discrete temperature ranges and drive outputs
  //
  if (temp_f > 80.0) {

    // hot condition: activate red led only
    //
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
  }
  else if ((temp_f >= 60.0) && (temp_f <= 80.0)) {

    // normal condition: activate green led only
    //
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
  }
  else {

    // cold condition: activate blue led only
    //
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
  }

  // pause execution before next sample iteration (500 ms)
  //
  delay(500);
}
