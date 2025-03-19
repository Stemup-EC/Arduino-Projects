// MQ Sensor Fire Detection Code for Arduino

const int MQ_PIN = A2;  // MQ sensor connected to analog pin A2
const int THRESHOLD = 400; // Threshold value for fire detection

void setup() {
    Serial.begin(9600); // Start serial communication
}

void loop() {
    int mqValue = analogRead(MQ_PIN); // Read MQ sensor value (0-1023)
    Serial.print("MQ Sensor Value: ");
    Serial.println(mqValue);
    
    if (mqValue > THRESHOLD) {
        Serial.println("EMERGENCY: Fire Detected! Take Immediate Action!");
    }
    
    delay(500); // Wait for 500ms before next reading
}
