void stateACPuerta() {
  if(machine.executeOnce){
    Serial.println("State 10");
    Serial.println("Abrir y cerrar puerta");
    digitalWrite (solenoide, HIGH);     //Abrir puerta
  }
  while(digitalRead(switchPuerta) == LOW){ //Esperar hasta que se abra la puerta
    delay (10);
  }
  delay (1000);
  while(digitalRead(switchPuerta) == HIGH){ //Esperar hasta que se cierre la puerta
    delay (10);
  }
  digitalWrite (solenoide, LOW);   //Cerrar la puerta
}

bool transitionS10S0(){
  if(digitalRead(solenoide) == LOW){
    return true;
  }else
  return false;
}
