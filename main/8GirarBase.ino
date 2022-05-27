int compuerta = 0;

void stateGirarBase() {
  if(machine.executeOnce){
  Serial.println("State 8");
  Serial.println("Girar base");
  }
// while (!Serial.available() > 0);{
//    Serial.println("Ingrese cual compartimento se requiere:");
//    compart = Serial.read();
//    Serial.println(compart);
//    delay(1000);
//    
//  //Cambias los steps
//  switch(compart){
//    case 'A':
//      Serial.println("Giro del compartimento 1");
//      steps = 68;
//      Movimientomotores();
//      compuerta = 1;
//    break;
//  
//    case 'B':
//      Serial.println("Giro del compartimento 2");
//      steps = 87;
//      Movimientomotores();
//      compuerta = 1;
//    break;
//  
//    case 'C':
//      Serial.println("Giro del compartimento 3");
//      steps = 106;
//      Movimientomotores();
//      compuerta = 1;
//    break;
//  
//    case 'D':
//      Serial.println("Giro del compartimento 4");
//      steps = 125;
//      Movimientomotores();
//      compuerta = 1;
//    break;
//  
//    case 'E':
//      Serial.println("Giro del compartimento 5");
//      steps = 142;
//      Movimientomotores();
//      compuerta = 1;
//    break;
//  
//    case 'F':
//      Serial.println("Giro del compartimento 6");
//      steps = 160;
//      Movimientomotores();
//      compuerta = 1;
//    break;
//  
//    case 'G':
//      Serial.println("Giro del compartimento 7");
//      steps = 178;
//      Movimientomotores();
//      compuerta = 1;
//    break;
//  
//    case 'H':
//      Serial.println("Giro del compartimento 8");
//      steps = 0;
//      Movimientomotores();
//      compuerta = 1;
//    break;
//  
//    case 'I':
//      Serial.println("Giro del compartimento 9");
//      steps = 16;
//      Movimientomotores();
//      compuerta = 1;
//    break;
//  
//    case 'J':
//      Serial.println("Giro del compartimento 10");
//      steps = 32;
//      Movimientomotores();
//      compuerta = 1;
//    break;
//  }
//  }
//  delay(1000);
}

bool transitionS8S9(){
//  if(compuerta == 1){
//    compuerta = 0;
//    return true;
//  }else{
//    return false;
//  }
return true;
}
