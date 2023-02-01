#include <SPI.h>
#include <SD.h>

File SaveDATA;
File SaveBAKEUPS;
File SaveTTN;
File SaveORG;
File SaveTBRG;
File SaveWDT;


void SDsetup(){
  
    if (!SD.begin(chipSelect)) {
//    Serial.println("initialization SD card failed.");
    while(1)
   {   
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second}
  }
  }
    //Serial.println("Finishing inicialize SD card.");
}

void saveDATAln(String data) {

   SDflag = 0;

    SaveDATA = SD.open(SAVE_DATA_FILE_NAME, FILE_WRITE);
    
  if (SaveDATA.size() == 0){    
        SaveDATA.println(DATA_Header);
        SaveDATA.flush();
     }

  if (SaveDATA) {
    SaveDATA.println(data);
    SaveDATA.close();
    SDflag = 1;
//    Serial.println("Save DATA to SD card done!");
  }    
//  
}


void saveBAKEUPSln(String data) {

    SaveBAKEUPS = SD.open(SAVE_BAKEUPS_FILE_NAME, FILE_WRITE);
    
  if (SaveBAKEUPS.size() == 0){    
        SaveBAKEUPS.println(BAKEUPS_Header);
        SaveBAKEUPS.flush();
     }

  if (SaveBAKEUPS) {
    SaveBAKEUPS.println(data);
    SaveBAKEUPS.close();
  }    
//  
}

void saveTTNln(String data) {

    SaveTTN = SD.open(SAVE_TTN_FILE_NAME, FILE_WRITE);
    
  if (SaveTTN.size() == 0){    
        SaveTTN.println(TTN_Header);
        SaveTTN.flush();
     }

  if (SaveTTN) {
    SaveTTN.println(data);
    SaveTTN.close();
  }    
//  Serial.println("Save TTN to SD card done!");
}


void saveORGln(String data) {

    SaveORG = SD.open(SAVE_ORG_FILE_NAME, FILE_WRITE);
    
  if (SaveORG.size() == 0){    
        SaveORG.println(ORG_Header);
        SaveORG.flush();
     }

  if (SaveORG) {
    SaveORG.print(data);
    SaveORG.close();
  }    
//  Serial.println("Save ORG to SD card done!");
}

void saveTBRGln(String data) {

    SaveTBRG = SD.open(SAVE_TBRG_FILE_NAME, FILE_WRITE);
    
  if (SaveTBRG.size() == 0){    
        SaveTBRG.println(TBRG_Header);
        SaveTBRG.flush();
     }

  if (SaveTBRG) {
    SaveTBRG.println(data);
    SaveTBRG.close();
  }    
}

void saveWDTln(String data) {


    SaveWDT = SD.open(SAVE_WDT_FILE_NAME, FILE_WRITE);
    
  if (SaveWDT.size() == 0){    
        SaveWDT.println(WDT_Header);
        SaveWDT.flush();
     }

  if (SaveWDT) {
    SaveWDT.println(data);
    SaveWDT.close();
  }    
//  
}
