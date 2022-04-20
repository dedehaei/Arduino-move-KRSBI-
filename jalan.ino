#include <IBusBM.h>
#include "move.h"

IBusBM ibus;
int rcCH1 = 0; // Left - Right
int rcCH2 = 0; // Forward - Reverse
int rcCH3 = 0; // Acceleration
int rcCH4 = 0; // Spin Control
bool rcCH6 = 0; // Mode Control

int readCHannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}


// Read the CHannel and return a boolean value
bool readSwitCH(byte CHannelInput, bool defaultValue) {
  int intDefaultValue = (defaultValue) ? 100 : 0;
  int CH = readCHannel(CHannelInput, 0, 100, intDefaultValue);
  return (CH > 50);}
  
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

  // AttaCH iBus object to serial port
  ibus.begin(Serial1);

}

void loop() {
  // put your main code here, to run repeatedly:
  rcCH1 = readCHannel(0, -100, 100, 0);
  rcCH2 = readCHannel(1, -100, 100, 0);
  rcCH3 = readCHannel(2, 0, 155, 0);
  rcCH4 = readCHannel(3, -100, 100, 0);
  rcCH6 = readSwitCH(4, false);

if(rcCH2>=50 && rcCH2 <= 100){
  maju();
  Serial.println("maju");}

else if(rcCH2>=-100 && rcCH2 <=-50 ){
  Serial.println("mundur");
  mundur();}
  
else if(rcCH1>=50 && rcCH1 <= 100){
  geserkanan();
  Serial.println("geser kanan");}

else if(rcCH1>=-100 && rcCH1 <=-50 ){
  geserkiri();
  Serial.println("geser kiri");}
  
else if (rcCH4>=-100 && rcCH4 <=-50 ){
  putarkiri();
  Serial.println("putar Kiri");}

else if(rcCH4>=50 && rcCH4 <= 100){
  putarkanan();
  Serial.println("putar kanan");
}

else {
  diam();
  Serial.println("diam");
}
  
}
