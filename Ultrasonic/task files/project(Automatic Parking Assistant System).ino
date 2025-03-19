#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

#define TRIG_PIN 9  
#define ECHO_PIN 10  
#define LED_PIN 7  
#define BUZZER_PIN 6  

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial BTSerial(2, 3);  

void setup() {
    Serial.begin(9600);
    BTSerial.begin(9600);
    lcd.begin();
    lcd.backlight();

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
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

    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print(" cm ");

    if (distance < 10) {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);
    }

    delay(500);
}
