void stateReconocerUsuario(){
  if(machine.executeOnce){
    Serial.println("State 5");
    Serial.println("Control de acceso: ");
  }
//    if (Serial.available()>0){
//    input = Serial.read();
//  }
  
}


bool transitionS5S7(){
  if(input == '6'){
    return true;
  }else
    return false;
}

bool transitionS5S9(){
    if(input == '7'){
    return true;
  }else
    return false;
}

bool transitionS5S8(){
    if(input == '8'){
    return true;
  }else
    return false;
}
