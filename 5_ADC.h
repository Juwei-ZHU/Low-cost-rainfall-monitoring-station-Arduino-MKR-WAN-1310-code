
void ADCget(void) 
{       
  
        BatteryCount = analogRead(A0);
        SolarPanelCount = analogRead(A1);

        BatteryVoltage = BatteryCount/1024.0*3.3*2;   
        SolarPanelVoltage = SolarPanelCount/1024.0*3.3*3;   

    delay(100);
}
