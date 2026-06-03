#include <SCServo.h>

SMS_STS st;

#define SERVO_RX 18
#define SERVO_TX 19

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial2.begin(1000000, SERIAL_8N1, SERVO_RX, SERVO_TX);
  st.pSerial = &Serial2;

  Serial.println("Scanning ST3215 IDs 0-20...");
}

void loop() {
  bool found = false;

  for (int id = 0; id <= 20; id++) {
    int pos = st.ReadPos(id);

    if (pos != -1) {
      Serial.print("Found ID: ");
      Serial.print(id);
      Serial.print(" Position: ");
      Serial.println(pos);
      found = true;
    }
    delay(30);
  }

  if (!found) Serial.println("No servo found.");
  Serial.println("----");
  delay(2000);
}