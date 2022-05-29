void stateActivarMotores() {
  if(machine.executeOnce){
    Serial.println("State 6");
    Serial.println("Dispensar");
  }
  
  while (!Serial.available() > 0);{
    Serial.println("Ingrese la dosis:");
    dosis = Serial.readString().toInt();
    Serial.println(dosis);
    delay(1000);
  while (!Serial.available() > 0);{
    Serial.println("Ingrese cual compartimento se requiere:");
    compartimentos = Serial.read();
    Serial.println(compartimentos);
    delay(1000);

for(int i = 1; i <= dosis; i++){
  Pdispensadas = dosis;
  switch(compartimentos){
    case 'A':
      Serial.println("Giro del compartimento 1");
      steps = 17;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'B':
      Serial.println("Giro del compartimento 2");
      steps = 35;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'C':
      Serial.println("Giro del compartimento 3");
      steps = 54;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'D':
      Serial.println("Giro del compartimento 4");
      steps = 71;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'E':
      Serial.println("Giro del compartimento 5");
      steps = 90;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'F':
      Serial.println("Giro del compartimento 6");
      steps = 108;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'G':
      Serial.println("Giro del compartimento 7");
      steps = 126;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'H':
      Serial.println("Giro del compartimento 8");
      steps = 145;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'I':
      Serial.println("Giro del compartimento 9");
      steps = 163;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'J':
      Serial.println("Giro del compartimento 10");
      steps = 182;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  }
}
}
}
delay(1000);
}

bool transitionS5S6(){
 if(Pdispensadas == 0){
  alarmas = 'A';
  return true;
 }else
  return false;
}
