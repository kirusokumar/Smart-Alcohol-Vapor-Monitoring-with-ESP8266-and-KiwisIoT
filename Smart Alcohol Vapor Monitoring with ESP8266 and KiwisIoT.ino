#include <KiwisIoT.h>

const int alcoholSensorPin = A0;

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* topicId = "YOUR_TOPIC_ID";

int alcoholReading = 0;

void setup() {
  Serial.begin(115200);

  pinMode(alcoholSensorPin, INPUT);

  // Initialize KiwisIoT using your configured credentials.
  kiwisiot.begin(ssid, password, topicId);

  Serial.println("Alcohol Vapour Monitoring Started");
}

void loop() {
  kiwisiot.run();

  alcoholReading = analogRead(alcoholSensorPin);

  Serial.print("Raw Sensor Reading: ");
  Serial.println(alcoholReading);

  // Send the raw reading to dashboard Channel 1.
  kiwisiot.send("1", alcoholReading);

  delay(2000);
}