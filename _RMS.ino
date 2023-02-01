/* PROGRAM OF A RAINFALL MONITORING STATION
 * UINSING ARDUINO MKR WAN 1310, RG-15, WH-SP-RG, DS3231 
 * Mind4Stormwater project: http://mind4stormwater.org, , feel free to use, reuse, modify, share!!
 * INSA Lyon
 * ZHU Qingchuan - qingchuan.zhu@insa-lyon.fr
 *  
 *  *  FUNCTIONS *  *
 *  Send data to The Things Network platform every 5 minutes
 *  Save data in SD card every minute
 *  
 //== all comments to check!!
*/ 
const String codeVersion ="5 December 2022"; //version of the code

const int stationNumber = 1; // change this to fit different stations!!! see details in TTN.h-> setAppEuiAndKey() function.


#include "0_Variables.h"
#include "1_Libraries.h"  


void prepareSDSave(){
    
    allData = 
    String(stationNumber) 
    + ", " +String(saveCount)
    + ", " + stringRTC() 
    + ", " + String(RG15Acc)    
    + ", " + String(raincnt)
    + ", " + String(BatteryVoltage)
    + ", " + String(SolarPanelVoltage)
    + ", " + String(temp)
    + ", " + codeVersion;

    ORGraw = 
    String(stationNumber) 
    + ", " +String(saveCount) 
    + ", " + stringRTC()
    + ", " + RG15;        

}

void prepareTTNSave(){
  
    allSend = 
    String(stationNumber) 
    + ", " +String(sendCount)    
    + ", " + stringRTC() 
    + ", " + String(RG15send) 
    + ", " + String(TBRGsend) 
    + ", " + String(BatteryVoltage)
    + ", " + String(SolarPanelVoltage)
    + ", " + String(temp);       
}

int i = 0; // Adding index for RG-15, ML8511 and SI1145

void setup () { 

//  Serial.begin(9600);
//  while(!Serial);
//  Serial.println(DATA_Header);

  pinMode(LED_BUILTIN, OUTPUT);

  WDTsetup();

  TTNsetup(); // Initialize the connection to TTN
  
  SDsetup(); // Initialize to use SD card

  DS3231setup(); // Initialize RTC DS3231
  
  RG15setup(); // Initialize RG-15 in the setup

  TBRGsetup();
  
}

void loop () {
  
  DateTime now = rtc.now();
  //Set now as RTC time
  Unixtime = now.unixtime();
  delay(500);

 if(now.second() == 0) { // Get data every minute:  

  MyWatchDoggy.clear();  // refresh wdt - before it loops

//  if(now.second()%5 == 0) { // Get data every 5 seconds:
  
  getRTC(now); // get date and time from DS3231
  
  getRG15(); // Ask RG-15 to report the accumulative rainfall in the last minute
  cutRG15(); // Cut the report string of RG-15 to get the value
  
  RG15ttn[i] = RG15Acc;
  
  TBRGttn[i] = raincnt;
 
  i = i + 1;

  ADCget();

  prepareSDSave(); // Prepare the string to save SD card

  saveDATAln(allData);

  saveBAKEUPSln(allData);

//  Serial.println(allData);
//  Serial.println(ORGraw);

  delay(100);
  
  saveORGln(ORGraw);

  saveCount = saveCount + 1;

  raincnt = 0;
  
  if(now.minute()%5 == 0) {  //send to TTN 5 every minute
   
   RG15send = RG15ttn[0]+RG15ttn[1]+RG15ttn[2]+RG15ttn[3]+RG15ttn[4];
   TBRGsend = TBRGttn[0]+TBRGttn[1]+TBRGttn[2]+TBRGttn[3]+TBRGttn[4];

   i = 0;

   prepareTTNSave();

   sendtoTTN();    

   saveTTNln(allSend);

   sendCount = sendCount + 1;
   
   raincnt = 0;

  }
  
  delay(1000);
   
  }
     
}
