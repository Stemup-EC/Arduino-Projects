#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 9  
#define ECHO_PIN 10  

LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup() {
    Serial.begin(9600);
    lcd.begin();
    lcd.backlight();
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

    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print(" cm ");

    delay(500);
}
