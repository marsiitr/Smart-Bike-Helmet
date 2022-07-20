# Smart-Bike-Helmet

<p align="justify">

<h2> Abstract </h2>

<p>
Smart Bike Helmet is a protective headgear that provides enhanced protection to the rider with advanced features such as alcohol detection, accident detection, and live location tracking. It protects the rider by not allowing the bike’s ignition to turn ON if he/she is drunk or not wearing the helmet. This is done using an RF module. Its main purpose is to detect possible accidents and notify the rider's family about the same with the current location so that help could be provided timely.
</p>

<p align="justify">

<h2> Motivation </h2>

<p>
Our inspiration was to learn the basics of IoT, Arduino, to work with sensors and to familiarize ourselves with the various platforms that are used for IoT through this project.
<br>
The aim of this project is to ensure safety of the rider and prevent deaths and injuries caused by road accidents. If such a product is used on a large scale then the number of road accident related deaths and cases would be reduced. It is because it would be compulsory to wear the helmet and not be drunk in order to ride the bike. Also in case an accident occurs, the family gets notified about it along with the current loccation of the driver. Through this we want to solve two issues : reducing the number of road accidents by reducing drink and drive cases and provision of timely treatment that could otherwise prove to be fatal.
</p>

<h2> Mechanical Aspect of the Design </h2>

<p>
The main body is a basic helmet to which various sensors are attached that gives it its functionality. An alcohol sensor has been fitted inside the helmet right in front of the mouth of the rider. Force sensitive resistor has been placed on the top so that it can sense whether the helmet is being worn or not. The rest of the sensors and microcontroller are placed inside a plastic box and secured at the back of the helmet.
</p>

<h2> Electronic Aspect of the Design </h2>
<h2> The sensors used are as follows: </h2>
<h3> ADXL345 Accelerometer </h3>

The ADXL345 is a low-power, 3-axis MEMS accelerometer modules with both I2C and SPI interfaces.The sensor consists of a micro-machined structure on a silicon wafer. The structure is suspended by polysilicon springs which allow it to deflect smoothly in any direction when subject to acceleration in the X, Y and/or Z axis. Deflection causes a change in capacitance between fixed plates and plates attached to the suspended structure. This change in capacitance on each axis is converted to an output voltage proportional to the acceleration on that axis.

<p align="center">
<img src="./images and videos/acc.PNG" alt="acc">
</p>

<h3> Vibration Module SW-420 </h3>

A vibration sensor is a device that measures the amount and frequency of vibration in a given system, machine, or piece of equipment.Vibration sensors are piezoelectric accelerometers that sense vibration. They are used for measuring fluctuating accelerations or speeds or for normal vibration measurement.

The vibration sensor module based on the vibration sensor SW-420 and Comparator LM393 is used to detect vibrations. During no vibration, the sensor provides Logic Low and when the vibration is detected, the sensor provides Logic High.
<br>

<p align="center">
<img src="./images and videos/vm.PNG">
</p>

<h3> RF Module </h3>

Generally, an RF module is a small size electronic device, that is used to transmit or receive radio signals between two devices. The main application of the RF module is an embedded system to communicate with another device wirelessly.
<br>
<p align="center">
<img src="./images and videos/rf.PNG">
</p>
<h3> MQ-3 Alcohol Sensor </h3>

The MQ-3 is Alcohol Sensitive Sensor that is often used in a breath analyzer.An alcohol sensor detects the attentiveness of alcohol gas in the air and an analog voltage is an output reading.
<br>
<p align="center">
<img src="./images and videos/as.PNG">
</p>

<h3> Force sensitive Resistor </h3>

A force-sensing resistor is a material whose resistance changes when a force, pressure or mechanical stress is applied. It is utilised to know whether the helmet is being worn or not.
<br>
<p align="center">
<img src="./images and videos/fsr.PNG">
</p>
<h3> GPS Module </h3>

The GPS receiver measures the distance to each satellite by the amount of time it takes to receive a transmitted signal. With distance measurements from a few more satellites, the receiver can determine a user's position and display it
<br>

<p align="center">
<img src="./images and videos/gps.PNG">
</p>

<h2> The microcontrollers used are: </h2>

<h3> Arduino UNO </h3>

<h3> NodeMCU </h3>

<h2> Software Aspect </h2>

<p>
IoT is a concept that refers to all the objects that are now connected to the internet and how they can communicate with each other or with the people around them. 
Iot architecture for our project is
</p>

<br>

<p align="center">
<img src="./images and videos/iotarchi.PNG" >
</p>

<br>
<br>
<br>

<p align="center">
<img src="./images and videos/dataflow.PNG">
</p>

<p>
Arduino IoT cloud services act as a cloud-based hosting platform connecting the NodeMCU to the cloud.
Wireless communication of messages to the rider's family are sent using PushBullet app.
</p>

<h2> Tech Stack </h2>

<h2> Cost Structure </h2>

<table>
    <tr>
        <th>COMPONENTS</th>
        <th>COST(in Rs.)</th>
    </tr>
    <tr>
        <td>Arduino UNO (QTY-2)
        <td>
    </tr>
    <tr>
        <td>NodeMCU ESP8266
        <td>
    </tr>
    <tr>
        <td>ADXL345 Accelerometer
        <td>
    </tr>
    <tr>
        <td>RF Transmitter and Receiver 433Mhz
        <td>
    </tr>
    <tr>
        <td>NEO-6M GPS Module
        <td>
    </tr>
    <tr>
        <td>Force Sensitive Resistor
        <td>
    </tr>
    <tr>
        <td>MQ3 Alcohol Sensor
        <td>
    </tr>
    <tr>
        <td>Jumper Wires
        <td>
    </tr>
    <tr>
        <td>Bike Helmet
        <td>300
    </tr>
    <tr>
        <td>Vibration Sensor module 
        <td>
    </tr>
</table>

<h2> Applications </h2>

<ul>
    <li>Accident prevention and real time safety system
    <li>Rescue requests
    <li>Provision of help in time
</ul>

<h2> Limitations </h2>

<ul>
    <li>False alarms are possible
    <li>GPS module not implemented
</ul>

<br>

<h2> Future Improvements </h2>

<ul>
    <li>Other sensors like heartbeat monitors, and oximeters can be introduced
    <li>Feedback mechanisms for the rider can be introduced
    <li>Can be designed for less power consumption
    <li>The microcontroller could be better placed so that it remains secure and safe from external stresses.
</ul>

<br>

<h2>Team Members</h2>
   <p>
 
 1. [Bhawna Rana](https://github.com/Bhawna-Rana)<br>
 2. [Sarish Nilakhe](https://github.com/Shinchan9913)<br>
 3. [Shiva Rama Raju](https://github.com/MSRRaju07)<br>
 4. [Rose Jethani](https://github.com/rose2221)<br>
 
   </p>
<br>

<h2>Mentors</h2>
   <p>

 1. [Nagesh Bansal](https://github.com/NageshBansal)<br>
 2. [Nishant Kumar](https://github.com/crooknish)<br>
 
   </p>
<br>

<h2> References </h2>