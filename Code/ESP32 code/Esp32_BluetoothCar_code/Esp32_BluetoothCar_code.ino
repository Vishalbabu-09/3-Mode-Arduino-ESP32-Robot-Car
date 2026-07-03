#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define ARDUINO_RX 32
#define ARDUINO_TX 14

HardwareSerial ArduinoSerial(1);

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32-Robot");

  ArduinoSerial.begin(9600, SERIAL_8N1, ARDUINO_RX, ARDUINO_TX);
  Serial.println("ESP32 Bluetooth Controller started");
}

void loop() {
  if (SerialBT.available()) {
    char cmd = SerialBT.read();
    ArduinoSerial.write(cmd);
    Serial.print("Sent to Arduino: ");
    Serial.println(cmd);
  }

  if (ArduinoSerial.available()) {
    char resp = ArduinoSerial.read();
    Serial.print("Arduino says: ");
    Serial.println(resp);
  }
}

