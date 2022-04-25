void stateRegistrarNFC(){
  if(machine.executeOnce){
  Serial.println("State4");
  Serial.println("Registrar NFC");
  }
 // if (Serial.available()>0){
   // input = Serial.read();
  //}
}


bool transitionS4S2(){
  return true;
}
