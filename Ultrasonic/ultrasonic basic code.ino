#define TRIG_PIN 9  // Trigger Pin
#define ECHO_PIN 10 // Echo Pin

void setup() {
    Serial.begin(9600);       // Start serial communication
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    long duration;
    float distance;

    // Send ultrasonic pulse
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read echo pulse duration
    duration = pulseIn(ECHO_PIN, HIGH);

    // Convert duration to distance (Speed of sound = 343 m/s)
    distance = (duration * 0.0343) / 2;  

    // Display distance
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}
