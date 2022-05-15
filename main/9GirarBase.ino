void stateGirarBase() {
  if(machine.executeOnce){
  Serial.println("State 9");
  Serial.println("Girar base");
  }
//while (!Serial.available() > 0);{
//  Serial.println("Ingrese cual compartimento se requiere:");
//  compartimentos = Serial.read();
//  Serial.println(compartimentos);
//
//for(int i = 1; i <= dosis; i++){
//  //Cambias los steps
//switch(compartimentos){
//  case 'A':
//    Serial.println("Giro del compartimento 1");
//    steps = 19;
//    Movimientomotores1();
//  break;
//
//  case 'B':
//    Serial.println("Giro del compartimento 2");
//    steps = 37;
//    Movimientomotores1();
//    
//  break;
//
//  case 'C':
//    Serial.println("Giro del compartimento 3");
//    steps = 56;
//    Movimientomotores1();
//  break;
//
//  case 'D':
//    Serial.println("Giro del compartimento 4");
//    steps = 73;
//    Movimientomotores1();
//  break;
//
//  case 'E':
//    Serial.println("Giro del compartimento 5");
//    steps = 92;
//    Movimientomotores1();
//  break;
//
//  case 'F':
//    Serial.println("Giro del compartimento 6");
//    steps = 110;
//    Movimientomotores1();
//  break;
//
//  case 'G':
//    Serial.println("Giro del compartimento 7");
//    steps = 128;
//    Movimientomotores1();
//  break;
//
//  case 'H':
//    Serial.println("Giro del compartimento 8");
//    steps = 147;
//    Movimientomotores1();
//  break;
//
//  case 'I':
//    Serial.println("Giro del compartimento 9");
//    steps = 165;
//    Movimientomotores1();
//  break;
//
//  case 'J':
//    Serial.println("Giro del compartimento 10");
//    steps = 184;
//    Movimientomotores1();
//  break;
//}
//}
//}
//delay(3000);
}

bool transitionS9S10(){
    return true;
}
