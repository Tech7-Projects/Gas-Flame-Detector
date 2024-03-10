#define BLYNK_TEMPLATE_ID "TMPL3hxyFVBKE"
#define BLYNK_TEMPLATE_NAME "detector"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "2O7zH_KsVe7X7zTKU15aUSiPR-Eg9rhx"; // Blynk authentication token
char ssid[] = "TKM";  // Your WiFi SSID
char pass[] = "thiyaguvasanthi";  // Your WiFi password

#include <SoftwareSerial.h>

SoftwareSerial espSerial(4, 5); // RX, TX (connect these to the corresponding pins on the Arduino)

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);
  
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  if (espSerial.available()) {
    String receivedData = espSerial.readStringUntil('\n');
    Serial.println(receivedData); // Print received data to serial monitor
    
    if (receivedData == "GAS_DETECTED") {
      Blynk.virtualWrite(V0, "Gas Detected!");
    } else if (receivedData == "NO_GAS_DETECTED") {
      Blynk.virtualWrite(V0, "No Gas Detected");
    } else if (receivedData == "FLAME_DETECTED") {
      Blynk.virtualWrite(V1, "Flame Detected!");
    } else if (receivedData == "NO_FLAME_DETECTED") {
      Blynk.virtualWrite(V1, "No Flame Detected");
    }
  }
  
  Blynk.run();
}
