void Movimientomotores1(){
  digitalWrite(enableBase, HIGH);
      delay(500);
      if(digitalRead(switchBase) == HIGH){
        while (digitalRead(switchBase) == HIGH) {
          digitalWrite(dirPin2, HIGH);
          digitalWrite(stepPin2, HIGH);
          delay(stepDelay2);
          digitalWrite(stepPin2, LOW);
          delay(stepDelay2);
        }      
      }else{
        while (digitalRead(switchBase) == LOW) {
          digitalWrite(dirPin2, LOW);
          digitalWrite(stepPin2, HIGH);
          delay(stepDelay);
          digitalWrite(stepPin2, LOW);
          delay(stepDelay);
        }
      }
      delay(1000);
      digitalWrite(dirPin2, HIGH);
      for (int x = 0; x < steps ; x++) {
        digitalWrite(stepPin2, HIGH);
        delay(stepDelay);
        digitalWrite(stepPin2, LOW);
        delay(stepDelay);
      }
}

void Movimientomotores2(){
  for (int j = 0; j <= 2 ; ++){
    for (int x = 0; x < 10 ; x++) { //La base gira 10 pasos para acomodar las pastillas
      digitalWrite(stepPin2, HIGH);
      delay(stepDelay);
      digitalWrite(stepPin2, LOW);
      delay(stepDelay);
    }
    delay(1000);
    for (int x = 0; x < 20 ; x++) { //Giro hacia el otro lado para acomodar las pastillas
      digitalWrite(stepPin2, LOW);
      delay(stepDelay);
      digitalWrite(stepPin2, LOW);
      delay(stepDelay);
    }
    delay(1000);
    for (int x = 0; x < 10 ; x++) { //Vuelve a su posición
      digitalWrite(stepPin2, HIGH);
      delay(stepDelay);
      digitalWrite(stepPin2, LOW);
      delay(stepDelay);
    }
    digitalWrite(enableCremallera, HIGH); 
    while (digitalRead(switchArriba) == LOW && digitalRead(boton) == HIGH){ //BAJA LA CREMALLERA AL COMPARTIMENTO
      //Activar una direccion y fijar la velocidad con stepDelay
      digitalWrite(dirPin, HIGH);
      // Giramos 200 pulsos para hacer una vuelta completa
      digitalWrite(stepPin, HIGH);
      delay(stepDelay);
      digitalWrite(stepPin, LOW);
      delay(stepDelay);
    }
    delay(2000); //Se detiene 2 segs
    while (digitalRead(switchAbajo) == LOW){ //SUBE LA CREMALLERA
       //Activar una direccion y fijar la velocidad con stepDelay
      digitalWrite(dirPin, LOW);
       // Giramos 200 pulsos para hacer una vuelta completa
      digitalWrite(stepPin, HIGH);
      delay(stepDelay);
      digitalWrite(stepPin, LOW);
      delay(stepDelay);
     }
     delay(1000);
  }
}

void Movimientomotores2(){
   while (digitalRead(switchBase) == LOW) { //VUELVE LA BASE A LA POSICION 0
    digitalWrite(dirPin2, LOW);
    digitalWrite(stepPin2, HIGH);
    delay(stepDelay);
    digitalWrite(stepPin2, LOW);
    delay(stepDelay);
   }
    delay(2000);
  while (digitalRead(switchArriba) == LOW){ //BAJA LA CREMALLERA
     //Activar una direccion y fijar la velocidad con stepDelay
    digitalWrite(dirPin, HIGH);
     // Giramos 200 pulsos para hacer una vuelta completa
    digitalWrite(stepPin, HIGH);
    delay(stepDelay);
    digitalWrite(stepPin, LOW);
    delay(stepDelay);
  }
    delay(2000); //Se detiene 2 segs
  while (digitalRead(switchAbajo) == LOW){ //SUBE LA CREMALLERA
     //Activar una direccion y fijar la velocidad con stepDelay
    digitalWrite(dirPin, LOW);
     // Giramos 200 pulsos para hacer una vuelta completa
    digitalWrite(stepPin, HIGH);
    delay(stepDelay);
    digitalWrite(stepPin, LOW);
    delay(stepDelay);
  }
  digitalWrite(enableBase, LOW);
  digitalWrite(enableCremallera, LOW);
    Pdispensadas--;
}
