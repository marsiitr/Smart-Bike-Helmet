#include <RH_ASK.h> 
#include <SPI.h> 
RH_ASK rf_driver;
void setup()
{
   pinMode(LED_BUILTIN, OUTPUT);
// Initialize ASK Object
rf_driver.init();
// Setup Serial Monitor
Serial.begin(9600);
}
 
void loop()
{
// Set buffer to size of expected message
uint8_t buf[11];
uint8_t buflen = sizeof(buf);
// Check if received packet is correct size
if (rf_driver.recv(buf, &amp;buflen))
{
Serial.print("Message Received: ");
Serial.println((char*)buf);
if((char*)buf == "1"){
  digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);}
}
}
