#define IR_SENSOR_PIN 7  // Define IR sensor input pin

void setup() {
    pinMode(IR_SENSOR_PIN, INPUT);  // Set pin 7 as input
    Serial.begin(9600);  // Start serial communication
}

void loop() {
    int sensorValue = digitalRead(IR_SENSOR_PIN);  // Read IR sensor data
    
    if (sensorValue == LOW) {
        Serial.println("Object Detected!");  // IR sensor detects an object
    } else {
        Serial.println("No Object Detected.");  // No object in front of the sensor
    }
    
    delay(500);  // Wait for 500ms before next reading
}
