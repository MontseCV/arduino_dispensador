void Movimientomotores(){
  digitalWrite(enableBase, HIGH);
  delay(500);
  //Primero asegura la posición 0 de los compartimentos
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
      for (int x = 0; x < steps ; x++) { //Da los pasos necesarios según el comapartimento
        digitalWrite(stepPin2, HIGH);
        delay(stepDelay);
        digitalWrite(stepPin2, LOW);
        delay(stepDelay);
      }
}

void Movimientomotores1(){
  digitalWrite(enableCremallera, HIGH); 
  int stepCounter = 0;
  while (digitalRead(boton) == HIGH and stepCounter<200 ){
    stepCounter++;//BAJA LA CREMALLERA AL COMPARTIMENTO
    //Activar una direccion y fijar la velocidad con stepDelay
    digitalWrite(dirPin, LOW);
    // Giramos 200 pulsos para hacer una vuelta completa
    digitalWrite(stepPin, HIGH);
    delay(stepDelay);
    digitalWrite(stepPin, LOW);
    delay(stepDelay);
  }
  delay(100);
  digitalWrite(valvula, LOW);
  delay(2000); //Se detiene 2 segs
  while (digitalRead(switchAbajo) == LOW){ //SUBE LA CREMALLERA
     //Activar una direccion y fijar la velocidad con stepDelay
    digitalWrite(dirPin, HIGH);
     // Giramos 200 pulsos para hacer una vuelta completa
    digitalWrite(stepPin, HIGH);
    delay(stepDelay);
    digitalWrite(stepPin, LOW);
    delay(stepDelay);
   }
  delay(1000);
}

void Movimientomotores2(){
  //Primero asegura la posición 0 de los compartimentos
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
 while (digitalRead(switchBase) == LOW) { //VUELVE LA BASE A LA POSICION 0
  digitalWrite(dirPin2, LOW);
  digitalWrite(stepPin2, HIGH);
  delay(stepDelay);
  digitalWrite(stepPin2, LOW);
  delay(stepDelay);
 }
  delay(1000);
while (digitalRead(switchArriba) == LOW){ //BAJA LA CREMALLERA
   //Activar una direccion y fijar la velocidad con stepDelay
  digitalWrite(dirPin, LOW);
   // Giramos 200 pulsos para hacer una vuelta completa
  digitalWrite(stepPin, HIGH);
  delay(stepDelay);
  digitalWrite(stepPin, LOW);
  delay(stepDelay);
}
  delay(100);
  digitalWrite(valvula, HIGH);
  delay(1000); //Se detiene 2 segs
while (digitalRead(switchAbajo) == LOW){ //SUBE LA CREMALLERA
   //Activar una direccion y fijar la velocidad con stepDelay
  digitalWrite(dirPin, HIGH);
   // Giramos 200 pulsos para hacer una vuelta completa
  digitalWrite(stepPin, HIGH);
  delay(stepDelay);
  digitalWrite(stepPin, LOW);
  delay(stepDelay);
}
digitalWrite(enableBase, LOW);
digitalWrite(enableCremallera, LOW);
}
