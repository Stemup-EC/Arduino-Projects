#include <SoftwareSerial.h>

#define TRIG_PIN 9  
#define ECHO_PIN 10  

SoftwareSerial BTSerial(2, 3);  // RX, TX

void setup() {
    Serial.begin(9600);
    BTSerial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
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

    BTSerial.print("Distance: ");
    BTSerial.print(distance);
    BTSerial.println(" cm");

    delay(500);
}
