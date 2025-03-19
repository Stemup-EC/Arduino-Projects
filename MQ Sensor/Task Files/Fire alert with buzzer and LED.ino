const int MQ_PIN = A2;
const int BUZZER_PIN = 9;
const int LED_PIN = 7;
const int THRESHOLD = 150;

void setup() {
    Serial.begin(9600);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int mqValue = analogRead(MQ_PIN);
    Serial.print("MQ Sensor Value: ");
    Serial.println(mqValue);

    if (mqValue > THRESHOLD) {
        Serial.println("EMERGENCY: Fire Detected!");
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(LED_PIN, LOW);
    }
    
    delay(500);
}
