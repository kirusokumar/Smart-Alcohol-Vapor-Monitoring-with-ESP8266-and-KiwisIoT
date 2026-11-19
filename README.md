# Smart Alcohol Vapor Monitoring with ESP8266 and KiwisIoT

An IoT-based alcohol vapor monitoring system using the **MQ-3 Alcohol Sensor** and **NodeMCU ESP8266** to collect sensor readings and visualize them remotely through the KiwisIoT cloud dashboard.

## Features

- Alcohol vapor detection using MQ-3 sensor.
- Real-time analog sensor readings.
- Wireless monitoring through ESP8266 Wi-Fi.
- Cloud dashboard visualization using KiwisIoT.
- Serial Monitor output for debugging.

## Hardware Components

- NodeMCU ESP8266
- MQ-3 Analog Alcohol Sensor
- Jumper Wires
- USB Cable

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library

## Circuit Connections

| MQ-3 Sensor | NodeMCU ESP8266 |
|---|---|
| VCC | Suitable 5V supply |
| GND | GND |
| AO | A0 (with suitable voltage scaling if required) |

**Important:** Verify the MQ-3 module's analog output voltage and the NodeMCU A0 input limit. Use a voltage divider or signal-conditioning circuit when necessary.

## KiwisIoT Dashboard

| Channel | Parameter |
|---|---|
| Channel 1 | Raw Alcohol Sensor Reading |

The sensor readings are transmitted to the KiwisIoT dashboard through Wi-Fi.

## Arduino Code

```cpp
#include <KiwisIoT.h>

const int alcoholSensorPin = A0;

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* topicId = "YOUR_TOPIC_ID";

KiwisIoT kiwisiot(ssid, password, topicId);

int alcoholReading = 0;

void setup() {
  Serial.begin(115200);

  pinMode(alcoholSensorPin, INPUT);

  kiwisiot.begin();

  Serial.println("Alcohol Vapour Monitoring Started");
}

void loop() {
  kiwisiot.run();

  alcoholReading = analogRead(alcoholSensorPin);

  Serial.print("Raw Sensor Reading: ");
  Serial.println(alcoholReading);

  kiwisiot.send("1", alcoholReading);

  delay(2000);
}
```

## Working Principle

1. The MQ-3 sensor responds to alcohol vapor in the surrounding air.
2. The sensor generates an analog output.
3. NodeMCU ESP8266 reads the analog value through A0.
4. The ESP8266 connects to Wi-Fi.
5. Sensor readings are transmitted to KiwisIoT through Channel 1.
6. The dashboard displays the changing sensor values.

## Applications

- Alcohol vapor monitoring demonstrations.
- IoT sensor monitoring experiments.
- Embedded systems learning.
- Wireless environmental sensing.
- Cloud-based sensor data visualization.

## Safety Note

This project is an educational prototype. Raw MQ-3 readings are not calibrated alcohol concentration measurements and must not be used to determine blood alcohol content, intoxication, or fitness to drive. It is not a certified breathalyzer or safety device.

## Libraries and Resources

- **KiwisIoT Website:** https://www.kiwisiot.in/
- **Arduino Library:** https://github.com/Kiwistron/KiwisIoT
- **Example Projects:** https://github.com/Kiwistron/KiwisIoT-Projects/tree/main

## Project Tutorial

[Smart Alcohol Vapor Monitoring with ESP8266 and KiwisIoT – Hackster.io](https://www.hackster.io/kirusokumar/smart-alcohol-vapor-monitoring-with-esp8266-and-kiwisiot-56b17c)

## Author

**Kirusokumar**

## License

Apache-2.0