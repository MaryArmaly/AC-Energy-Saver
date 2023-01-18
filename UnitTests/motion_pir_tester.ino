/*
PIR HCSR501 
modified on 5 Feb 2019
by Saeed Hosseini @ ElectroPeak
https://electropeak.com/learn/guides/
*/
int pirPin = 21;                 // PIR Out pin 

int pirStat = 0;                   // PIR status

void setup() {
   
 Serial.begin(9600);
}
void loop(){
  delay(200);
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) {            // if motion detected
   Serial.println("Hey I got you on on on!!!");
 } 
 else {
   Serial.println("Hey off off off");
 }
} 
