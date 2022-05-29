void stateACPuerta() {
  if(machine.executeOnce){
    Serial.println("State 10");
    Serial.println("Abrir y cerrar puerta");
    digitalWrite (solenoide, LOW);     //Abrir puerta
  }
  while(digitalRead(switchPuerta) == LOW){ //Esperar hasta que se abra la puerta
    delay (10);
  }
  delay (500);
  while(digitalRead(switchPuerta) == HIGH){ //Esperar hasta que se cierre la puerta
    delay (10);
  }
  digitalWrite (solenoide, HIGH);   //Cerrar la puerta
}

bool transitionS8S0(){
  if(digitalRead(solenoide) == HIGH){
    return true;
  }else
  return false;
}
