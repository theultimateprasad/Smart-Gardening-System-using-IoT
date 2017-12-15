/*************************************************************
 Author : Prasad Raspaile
 Website : www.prasadraspaile.com
 Project level : Beginner
 *************************************************************
  
  AIM : This example shows how you can control the relay from the Blynk App
  
  Hardware Requirements :
  1. NodeMCU 1.0 Board - 1no.
  2. MicroUSB Cable for Power Supply and Programming
  3. A full size breadboard
  4. LED as an indicator
  5. Connecting wires
  6. Tools - (if required) - Nose plier, wire-stripper, 

  App project setup:
  Hardware Connections
  LED is attched to D0
*************************************************************/
int LED = D0;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

}

void loop() {
 digitalWrite(LED, LOW);
 delay(1000);
 digitalWrite(LED, HIGH);
 delay(1000);

}
