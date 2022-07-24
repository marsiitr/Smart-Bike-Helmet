#include <Wire.h>               // Wire library - used for I2C communication
#include <RH_ASK.h>
#include <SPI.h>                // Not actually used but needed to compile
int ADXL345 = 0x53;             // The ADXL345 sensor I2C address
int fsrPin = 1;
#define vibrPin A2
#define alcPin A0
RH_ASK driver;
int starttime, endtime;
bool helmetworn = false;
bool bikestat = false;
bool firsttest = false;
bool accidentStatus = false;


void setup() {
  Serial.begin(9600);                    // Initiate serial communication for printing the results on the Serial monitor
  Wire.begin();                          // Initiate the Wire library
  // Set ADXL345 in measuring mode
  Wire.beginTransmission(ADXL345);       // Start communicating with the device
  Wire.write(0x2D);                      // Access/ talk to POWER_CTL Register - 0x2D
  // Enable measurement
  Wire.write(8);                         // (8dec -> 0000 1000 binary) Bit D3 High for measuring enable
  Wire.endTransmission();
  delay(10);

  if (!driver.init())                    //Check RF Module
    Serial.println("init failed");


  //need to run this code only once when arduino is powered
  float fsr = force();
  float alc = alcohol();
  if (fsr > 25) {
    starttime = millis();
    endtime = starttime;
    while ((endtime - starttime) <= 300000) // do this loop for up to 5min only
    {
      if (alc < 200) {
        if (firsttest == false) {
          turnonBike();
          firsttest = true;
        }
        if (accidentDetect()) {
          accidentStatus = true;
        }
      }
      else {
        turnoffBike();
      }
      endtime = millis();
    }

    if (accidentDetect()) {
      accidentStatus = true;
    }
  }
  else {
    turnoffBike();
  }
}

void loop() {
  int fsr = force();
  if (fsr > 25) {
    if (accidentDetect()) {
      accidentStatus = true;
    }
  }
  else {
    turnoffBike();
  }
}

float acceleration() {
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  float ax = ( Wire.read() | Wire.read() << 8); // X-axis value
  ax = ax / 256; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
  float ay = ( Wire.read() | Wire.read() << 8); // Y-axis value
  ay = ay / 256;
  float az = ( Wire.read() | Wire.read() << 8); // Z-axis value
  az = az / 256;
  float acceleration = sqrt(ax * ax + ay * ay + az * az);
  return acceleration;
}


int force() {
  int fsrReading = analogRead(fsrPin);
  return fsrReading;
}

float vibration() {
  float vibrReading = analogRead(vibrPin);
  return vibrReading;
}

float alcohol() {
  float alcReading = analogRead(alcPin);
  return alcReading;
}

void turnoffBike() {
  const char *msg = "0";
  driver.send((uint8_t *)msg, strlen(msg) + 1);
  driver.waitPacketSent();
}

void turnonBike() {
  const char *msg = "1";
  driver.send((uint8_t *)msg, strlen(msg) + 1);
  driver.waitPacketSent();
}

bool accidentDetect() {
  float vibration1 = vibration();
  float vibration2, Vib, Acc;
  float a1, a2, a3, a4;
  a1 = acceleration();
  delay(250);
  vibration2 = vibration();
  if (vibration2 > vibration1)vibration1 = vibration2;
  a2 = acceleration();
  delay(250);
  vibration2 = vibration();
  if (vibration2 > vibration1)vibration1 = vibration2;
  a3 = acceleration();
  delay(250);
  vibration2 = vibration();
  if (vibration2 > vibration1)vibration1 = vibration2;
  a4 = acceleration();
  delay(250);
  vibration2 = vibration();
  if (vibration2 > vibration1)vibration1= vibration2;
  if ( abs((a1 + a2 + a3 + a4) / 4) >= 1.3 || abs(vibration1) > 1000) {
    //accident might have occured
    delay(10000);
    //check after 10 seconds
    Acc = acceleration();
    Vib = vibration();
    if (Vib == 0 || Vib > 1000 || abs(Acc) > 2.3 || abs(Acc) < 1.2 ) {
      return true;
    }
  }
  return false;
}
