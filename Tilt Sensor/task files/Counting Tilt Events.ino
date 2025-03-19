#define TILT_SENSOR_PIN 7  

int tiltCount = 0;  
bool lastState = LOW;

void setup() {
    pinMode(TILT_SENSOR_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    int sensorState = digitalRead(TILT_SENSOR_PIN);

    if (sensorState == HIGH && lastState == LOW) {  
        tiltCount++;  
        Serial.print("Tilt Detected! Count: ");
        Serial.println(tiltCount);
    }
    
    lastState = sensorState;
    delay(500);
}
