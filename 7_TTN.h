#include <MKRWAN_v2.h>

LoRaModem modem;

void setAppEuiAndKey(){
  switch(stationNumber){
    case 1:
    {
      appEui="0000000000000002";   
      appKey="Need add!!!!"; 
    break;
    }
    case 2:
    {
      appEui="0000000000000002";   
      appKey="Need add!!!!"; 
    break;
    }
    case 3:
    {
      appEui="0000000000000002";   
      appKey="Need add!!!!"; 
    break;
    }
  }
}

void TTNsetup() {

  setAppEuiAndKey();
//  Serial.println("Start connecting to TTN"); 
  modem.begin(EU868);
      
//   if (! modem.begin(EU868)) 
//   Serial.println("Failed to start module."); 
  
  int connected = modem.joinOTAA(appEui, appKey);
// if(!connected)
//  Serial.println("Can not connected to TTN; are you indoor? Move near a window and retry.");
  
}

void sendtoTTN(){ // function to send data to TTN
  
  byte payload[21];

  payload[0] = sendCount;
  payload[1] = year-2000; 
  payload[2] = month;
  payload[3] = day; 
  payload[4] = hour;
  payload[5] = minute;
  payload[6] = second;
  
  payload[7] = int(RG15ttn[0]*100);
  payload[8] = int(RG15ttn[1]*100);
  payload[9] = int(RG15ttn[2]*100);
  payload[10] = int(RG15ttn[3]*100);
  payload[11] = int(RG15ttn[4]*100);

  payload[12] = TBRGttn[0];
  payload[13] = TBRGttn[1];
  payload[14] = TBRGttn[2];
  payload[15] = TBRGttn[3];
  payload[16] = TBRGttn[4];

  payload[17] = temp+20;
  payload[18] = int((BatteryVoltage-3)*60);
  payload[19] = int((SolarPanelVoltage-3)*60);
  payload[20] = SDflag;
  
  modem.setPort(3);
  modem.beginPacket();
  modem.write(payload, sizeof(payload));   
  modem.endPacket(false);
//  Serial.println("Sending to TTN has finished");
  delay(1000);
}
