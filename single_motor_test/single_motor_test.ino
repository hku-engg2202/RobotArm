#include <SCServo.h>

SMS_STS st;

#define SERVO_RX 18
#define SERVO_TX 19
#define SERVO_ID 4

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial2.begin(1000000, SERIAL_8N1, SERVO_RX, SERVO_TX);
  st.pSerial = &Serial2;

  Serial.println("Moving servo ID 4...");

  st.WritePosEx(SERVO_ID, 2048, 500, 50);
  delay(2000);

  st.WritePosEx(SERVO_ID, 2400, 500, 50);
  delay(2000);

  st.WritePosEx(SERVO_ID, 1700, 500, 50);
  delay(2000);

  st.WritePosEx(SERVO_ID, 2048, 500, 50);
  delay(2000);

  Serial.println("Test finished.");
}

void loop() {
}
