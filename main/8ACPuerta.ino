void stateACPuerta() {
  if(machine.executeOnce){
    Serial.println("State 10");
    Serial.println("Abrir y cerrar puerta");
    digitalWrite (solenoide, LOW);     //Abrir puerta
  }
  delay(1000);
  digitalWrite(solenoide,HIGH);
  while(digitalRead(switchPuerta) == LOW){ //Esperar hasta que se abra la puerta
    delay (10);
  }
  delay (500);
  while(digitalRead(switchPuerta) == HIGH){ //Esperar hasta que se cierre la puerta
    delay (10);
  }
}

bool transitionS8S0(){
  if(digitalRead(switchPuerta) == LOW){
    return true;
  }else
  return false;
}
