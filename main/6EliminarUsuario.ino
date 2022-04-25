void stateEliminarUsuario(){
  if(machine.executeOnce){
    Serial.println("State 6");
    Serial.println("Usuario eliminado");
  }
//    if (Serial.available()>0){
//    input = Serial.read();
//  }
  
}


bool transitionS6S2(){
    return true;
}
