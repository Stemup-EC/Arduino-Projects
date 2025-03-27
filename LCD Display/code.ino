#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address (0x27 or 0x3F based on your module)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  lcd.init();        // Initialize the LCD
  lcd.backlight();   // Turn on backlight
  lcd.setCursor(0, 0);  // Set cursor to column 0, row 0
  lcd.print("Hello, World!"); // Print message
}

void loop() {
  // Nothing here, message stays on screen
}
