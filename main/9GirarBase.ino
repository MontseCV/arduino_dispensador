void stateGirarBase() {
  if(machine.executeOnce){
  Serial.println("State 9");
  Serial.println("Girar base");
  }
//    if (Serial.available()>0){
//    input = Serial.read();
//  } 
}


bool transitionS9S10(){
    return true;
}
