const int analogPin = A0;  // Analog output from raindrop sensor
const int digitalPin = 2;  // Digital output from raindrop sensor
const int ledPin = 7;     // LED (or buzzer) for rain alert

void setup() {
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int rainAnalog = analogRead(analogPin);  // Read analog value (0-1023)
  int rainDigital = digitalRead(digitalPin); // Read digital value (0 or 1)

  Serial.print("Analog Value: ");
  Serial.print(rainAnalog);
  Serial.print(" | Digital Value: ");
  Serial.println(rainDigital);

  if (rainDigital == 0) { // When it rains (threshold reached)
    Serial.println("💧 Rain Detected! LED ON");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("☀️ No Rain. LED OFF");
    digitalWrite(ledPin, LOW);
  }

  delay(1000); // Wait 1 second before next reading
}
