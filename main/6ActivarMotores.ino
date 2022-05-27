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
  switch(compartimentos){
    case 'A':
      Pdispensadas = dosis;
      Serial.println("Giro del compartimento 1");
      steps = 19;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'B':
      Pdispensadas = dosis;
      Serial.println("Giro del compartimento 2");
      steps = 37;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'C':
      Pdispensadas = dosis;
      Serial.println("Giro del compartimento 3");
      steps = 56;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'D':
      Pdispensadas = dosis;
      Serial.println("Giro del compartimento 4");
      steps = 73;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'E':
      Pdispensadas = dosis;
      Serial.println("Giro del compartimento 5");
      steps = 92;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'F':
      Pdispensadas = dosis;
      Serial.println("Giro del compartimento 6");
      steps = 110;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'G':
      Pdispensadas = dosis;
      Serial.println("Giro del compartimento 7");
      steps = 128;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'H':
      Pdispensadas = dosis;
      Serial.println("Giro del compartimento 8");
      steps = 147;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'I':
      Pdispensadas = dosis;
      Serial.println("Giro del compartimento 9");
      steps = 165;
      Movimientomotores();
      Movimientomotores1();
      Movimientomotores2();
      Serial.print("Quedan por dispensar:");
      Serial.println(Pdispensadas);
    break;
  
    case 'J':
      Pdispensadas = dosis;
      Serial.println("Giro del compartimento 10");
      steps = 184;
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

bool transitionS6S7(){
 if(Pdispensadas == 0){
  alarmas = 'A';
  return true;
 }else
  return false;
}
