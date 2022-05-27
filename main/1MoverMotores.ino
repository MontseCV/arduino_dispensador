//Mover motores
void stateMoverMotores() {
  if(machine.executeOnce){
  Serial.println("State1");
  Serial.println("Moviendo motores");
  }
//  HIGH = ABIERTO, LOW = CERRADO ---- switches
    if (digitalRead(switchAbajo) == LOW){ //Cremallera posición 0 
    delay(500);
    digitalWrite(enableCremallera, HIGH);
    delay(500);
    while (digitalRead(switchAbajo) == LOW){
       //Activar una direccion y fijar la velocidad con stepDelay
       digitalWrite(dirPin, HIGH);
       // Giramos 200 pulsos para hacer una vuelta completa
      digitalWrite(stepPin, HIGH);
      delay(stepDelay);
      digitalWrite(stepPin, LOW);
      delay(stepDelay);
    }
    digitalWrite(enableCremallera, LOW);
  }
  
  else if (digitalRead(switchArriba) == LOW && digitalRead(switchAbajo) == HIGH){ //Base posición 0
    
      delay(500);
      digitalWrite(enableBase, HIGH);
      delay(500);
      while (digitalRead(switchBase) == LOW){
        digitalWrite(dirPin2, LOW);
        digitalWrite(stepPin2, HIGH);
        delay(stepDelay);
        digitalWrite(stepPin2, LOW);
        delay(stepDelay);
    }
    digitalWrite(enableBase, LOW);
  }
 delay(10);

}

bool transitionS1S2(){
  if(digitalRead(switchBase) == HIGH && digitalRead(switchArriba) == LOW && digitalRead(switchAbajo) == HIGH){
    return true;
  }else
    return false;
}
