String sms = " ";
String sonora = " ";

void stateMandarAlarma() {
  if(machine.executeOnce){
  Serial.println("State 8");
    Serial.println("*Alarma");
  }
if (transitionS5S8() == true){
  Serial.println("Mandando alarma");
}

  
//    if (Serial.available()>0){
//    input = Serial.read();
//  } 
}


bool transitionS8S0(){
    return true;
}
