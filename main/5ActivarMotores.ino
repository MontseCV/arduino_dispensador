void stateActivarMotores() {
  if(machine.executeOnce){
    Serial.println("State 6");
    Serial.println("Dispensar");
  }
    Serial.println("Ingrese la dosis:");
  while (!Serial.available() > 0);{ 
    dosis = Serial.readString().toInt();
    Serial.println(dosis);
    delay(1000);
  while (!Serial.available() > 0);{
    Serial.println("Ingrese cual compartimento se requiere:");
    compartimentos = Serial.read();
    Serial.println(compartimentos);
    delay(1000);

for(int i = 1; i <= dosis; i++){
  switch(compartimentos){
    case 'A':
      Serial.println("Giro del compartimento 1");
      steps = 15;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
    break;
  
    case 'B':
      Serial.println("Giro del compartimento 2");
      steps = 33;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
    break;
  
    case 'C':
      Serial.println("Giro del compartimento 3");
      steps = 51;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
    break;
  
    case 'D':
      Serial.println("Giro del compartimento 4");
      steps = 71;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
    break;
  
    case 'E':
      Serial.println("Giro del compartimento 5");
      steps = 89;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
    break;
  
    case 'F':
      Serial.println("Giro del compartimento 6");
      steps = 107;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
    break;
  
    case 'G':
      Serial.println("Giro del compartimento 7");
      steps = 125;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
    break;
  
    case 'H':
      Serial.println("Giro del compartimento 8");
      steps = 143;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
    break;
  
    case 'I':
      Serial.println("Giro del compartimento 9");
      steps = 160;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
    break;
  
    case 'J':
      Serial.println("Giro del compartimento 10");
      steps = 180;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
    break;

    case 'K':
      Pdispensadas = 1;
    break;
  }
}
}
}
delay(1000);
}

bool transitionS5S6(){
 if(Pdispensadas == 1){
  Pdispensadas = 0;
  alarmas = 'A';
  return true;
 }else
  return false;
}
