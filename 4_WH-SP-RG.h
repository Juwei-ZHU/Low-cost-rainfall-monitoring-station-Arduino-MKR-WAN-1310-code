
void InterruptRain()
 {
  if((long)(micros() - last_micros_rain) >= debouncing_time_rain_gauge * 1000) // ignore the next tip if it is too close to last tip
  {
   if (digitalRead(rainPin)==HIGH) 
  {
  raincnt++; 
  Serial.println(raincnt);
  saveTBRGln(String(Unixtime)); 
  
  last_micros_rain = micros(); 
  }
  }  
}

void TBRGsetup()
{
   pinMode(rainPin, INPUT); 
   attachInterrupt(digitalPinToInterrupt(rainPin),InterruptRain,RISING);  
}
