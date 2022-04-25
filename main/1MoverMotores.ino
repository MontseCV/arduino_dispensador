//Mover motores
void stateMoverMotores() {
  if(machine.executeOnce){
  Serial.println("State0");
  Serial.println("Moviendo motores");
  }
//  HIGH = ABIERTO, LOW = CERRADO ---- switches
//  if (digitalRead(switchArriba) == HIGH && digitalRead(switchAbajo) == LOW){
//    while (digitalRead(switchAbajo) == LOW){
//       //Activar una direccion y fijar la velocidad con stepDelay
//       digitalWrite(dirPin, LOW);
//       // Giramos 200 pulsos para hacer una vuelta completa
//      digitalWrite(stepPin, HIGH);
//      delay(stepDelay);
//      digitalWrite(stepPin, LOW);
//      delay(stepDelay);
//    }
//  }
//
//  else if (digitalRead(switchArriba) == LOW && digitalRead(switchAbajo) == HIGH){
//     while (digitalRead(switchBase) == LOW){
//      digitalWrite(dirPin2, LOW);
//      digitalWrite(stepPin2, HIGH);
//      delay(stepDelay);
//      digitalWrite(stepPin2, LOW);
//      delay(stepDelay);
//    }
//  }
// delay(10);

//  if (Serial.available()>0){
//    input = Serial.read();
//  }
}

bool transitionS1S2(){
    if(input == '1'){
    return true;
  }else
    return false;
}
