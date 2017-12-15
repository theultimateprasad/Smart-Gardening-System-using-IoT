/*************************************************************
 Author : Prasad Raspaile
 Website : www.prasadraspaile.com
 Project level : Intermidiate
 *************************************************************
  
  AIM : This example shows how you can control the gardening system using IoT
  
  Hardware Requirements :
  1. NodeMCU 1.0 Board - 1no.
  2. MicroUSB Cable for Power Supply and Programming
  3. A full size breadboard
  4. LED as an indicator
  5. 5V single Channel Relay Board
  6. Connecting wires
  7. Tools - (if required) - Nose plier, wire-stripper, 
  8. 12V Dc motor for watering to be connected at Relay

  App project setup:
  using Blynk Virtual Variables :
  Soil Moisture Sensor is attched to V0
  Relay 1 is attached to V1

*************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Auth_Token_received_on_mail_from_Blynk_App";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WiFi-SSID";
char pass[] = "WiFi-Password";

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (V0).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float soil = analogRead(A0);
  float Soil = map(soil,0,1000,0,100); 

  Blynk.virtualWrite(V0, Soil);

}

BLYNK_WRITE(V1)
{
  digitalWrite(D5,param.asInt());
}



void setup()
{
  pinMode(D5,OUTPUT);
  digitalWrite(D5,LOW);
  
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}

