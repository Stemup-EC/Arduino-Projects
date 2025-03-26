#define SOIL_MOISTURE_PIN A0  // Analog pin for sensor

void setup() {
  Serial.begin(9600); // Start serial communication
}

void loop() {
  int sensorValue = analogRead(SOIL_MOISTURE_PIN); // Read moisture value
  Serial.print("Soil Moisture Level: ");
  Serial.println(sensorValue); // Print value to Serial Monitor
  delay(1000); // Wait 1 second before next reading
}
