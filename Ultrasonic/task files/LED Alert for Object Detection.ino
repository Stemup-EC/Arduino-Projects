#define TRIG_PIN 9  
#define ECHO_PIN 10  
#define LED_PIN 7  

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    long duration;
    float distance;

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);
    distance = (duration * 0.0343) / 2;  

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 10) {
        digitalWrite(LED_PIN, HIGH);  // Turn LED ON
    } else {
        digitalWrite(LED_PIN, LOW);   // Turn LED OFF
    }

    delay(500);
}
