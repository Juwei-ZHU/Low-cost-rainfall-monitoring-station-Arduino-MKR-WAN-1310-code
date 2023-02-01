String allData;
String ORGraw;
String allSend;

uint8_t saveCount = 0;
uint8_t sendCount = 0;

//***DS3231 part***********************************
 
int year;
int month;
int day;
int hour;
int minute;
int second;
int temp;

//***ADC part**************************************

int16_t BatteryCount = 0; 
int16_t SolarPanelCount = 0;

float BatteryVoltage = 0;
float SolarPanelVoltage = 0;

//***RG-15*****************************************
//https://rainsensors.com/docs/rg-guides/rg-arduino-guide/taking-the-serialized-data-further/

String RG15;
float RG15Acc;

//***WH-SP-RG****************************************

uint32_t Unixtime = 0; // variable to save time of every tip

const byte rainPin = 6; 
long debouncing_time_rain_gauge = 1000; 
volatile unsigned long last_micros_rain = 0; 
unsigned int raincnt = 0; 

//***TTN*******************************************

String appEui=" ";                                             
String appKey=" "; 

float RG15ttn[5] = {0,0,0,0,0};
float RG15send;

int TBRGttn[5] = {0,0,0,0,0};
int TBRGsend;

//***SD********************************************

int SDflag = 0;

const int chipSelect = 4;

const String SAVE_DATA_FILE_NAME = "DATA"+String(stationNumber)+".CSV";
String DATA_Header = "Station, Count, DS3231 (UTC), RG-15 (mm/min), TBRG Acc (tips/min), Battery Voltage (V), Solar Panel Voltage (V), Temperature (Celsius), Code version";

const String SAVE_BAKEUPS_FILE_NAME = "BAK"+String(stationNumber)+".BAK";
String BAKEUPS_Header = "Station, Count, DS3231 (UTC), RG-15 (mm/min), TBRG Acc (tips/min), Battery Voltage (V), Solar Panel Voltage (V), Temperature (Celsius), Code version";

const String SAVE_TTN_FILE_NAME = "TTNSum"+String(stationNumber)+".CSV";
String TTN_Header = "Station, Count, DS3231 (UTC), RG-15 Acc (mm/5min), TBRG counts (tips/5min), Battery Voltage (V), Solar Panel Voltage (V), Temperature (Celsius)";

const String SAVE_ORG_FILE_NAME = "ORGRaw"+String(stationNumber)+".CSV";
String ORG_Header = "Station, Count,  DS3231 (UTC),  RG-15 Raw String";

const String SAVE_TBRG_FILE_NAME = "TBRGRaw"+String(stationNumber)+".CSV";
String TBRG_Header = "Time of tips (/3600/24 + 25569) (UTC)";

const String SAVE_WDT_FILE_NAME = "WDT"+String(stationNumber)+".CSV";
String WDT_Header = "Time";
