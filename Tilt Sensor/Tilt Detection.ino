#define TILT_SENSOR_PIN 7  // Define the tilt sensor pin

void setup() {
    pinMode(TILT_SENSOR_PIN, INPUT);  // Set sensor pin as input
    Serial.begin(9600);  // Start serial communication
}

void loop() {
    int sensorState = digitalRead(TILT_SENSOR_PIN);  // Read sensor state

    if (sensorState == HIGH) {  // Tilt detected
        Serial.println("Tilt Detected!");
    } else {
        Serial.println("No Tilt Detected.");
    }
    
    delay(500);  // Delay to avoid bouncing effect
}
