
#include <SoftwareSerial.h>
SoftwareSerial node(D1 , D2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  node.begin(9600);
}

void loop() {
  
  String fsr = node.readStringUntil('\r');
  Serial.println(fsr);
  delay(800);
  String alc = node.readStringUntil('\r');
  Serial.println(alc);
  delay(800);
  
}
