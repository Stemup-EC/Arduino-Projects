#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int MQ_PIN = A2;
const int BUZZER_PIN = 9;
const int LED_PIN = 7;
const int THRESHOLD = 150;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(9600);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    
    lcd.begin();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Fire Detector");
}

void loop() {
    int mqValue = analogRead(MQ_PIN);
    Serial.print("MQ Sensor Value: ");
    Serial.println(mqValue);

    lcd.setCursor(0, 1);
    lcd.print("Value: ");
    lcd.print(mqValue);
    lcd.print("   "); 

    if (mqValue > THRESHOLD) {
        Serial.println("EMERGENCY: Fire Detected!");
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_PIN, HIGH);
        lcd.setCursor(0, 0);
        lcd.print("FIRE DETECTED! ");
    } else {
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(LED_PIN, LOW);
        lcd.setCursor(0, 0);
        lcd.print("Status: Normal ");
    }
    
    delay(500);
}
