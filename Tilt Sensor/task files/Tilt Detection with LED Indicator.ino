#define TILT_SENSOR_PIN 7  
#define LED_PIN 9  

void setup() {
    pinMode(TILT_SENSOR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int sensorState = digitalRead(TILT_SENSOR_PIN);

    if (sensorState == HIGH) {  
        Serial.println("Tilt Detected!");
        digitalWrite(LED_PIN, HIGH);  
    } else {
        Serial.println("No Tilt Detected.");
        digitalWrite(LED_PIN, LOW);
    }
    
    delay(500);
}
