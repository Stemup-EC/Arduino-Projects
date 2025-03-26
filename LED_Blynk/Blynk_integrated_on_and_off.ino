#define BLYNK_TEMPLATE_ID "TMPL3XnrwoTGN"
#define BLYNK_TEMPLATE_NAME "LED"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// 🔹 Blynk Auth Token (Copy from Email or Web Dashboard)
char auth[] = "e0pfj9jZJMctlBM0ol0spC5f90qgL7Q-";

// 🔹 WiFi Credentials
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

#define LED_PIN 4  // LED on GPIO4

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0) {  // Virtual Pin V0 (Button in App)
  int ledState = param.asInt();
  digitalWrite(LED_PIN, ledState);
}

void loop() {
  Blynk.run();
}
