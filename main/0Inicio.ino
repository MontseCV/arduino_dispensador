void state0() {
  if(machine.executeOnce){
  Serial.println("Inicio");
  }
  h=0;
}

bool transitionS0S1(){
      return true;
}
