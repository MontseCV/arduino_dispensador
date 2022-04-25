void stateActivarMotores() {
  if(machine.executeOnce){
    Serial.println("State 7");
    Serial.println("Dispensar");
  }
//    if (Serial.available()>0){
//    input = Serial.read();
//  } 
}


bool transitionS7S8(){
    return true;
}
