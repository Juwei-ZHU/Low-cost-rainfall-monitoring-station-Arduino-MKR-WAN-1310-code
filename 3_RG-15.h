//https://rainsensors.com/docs/rg-guides/rg-arduino-guide/taking-the-serialized-data-further/


void RG15setup(){
    
  Serial1.begin(9600);

}

void getRG15() { // ask RG-15 to report data

  Serial1.println('r');
  delay(50);
 while (Serial1.available()) {
  RG15 = Serial1.readString();

}

}

void cutRG15(){
  
  int index1 = RG15.indexOf('Acc'); // According to the location of 'Acc' to cut the report string of RG-15
  int index2 = RG15.indexOf('mm');
  RG15Acc = (RG15.substring(index1+2,index2)).toFloat();

}
