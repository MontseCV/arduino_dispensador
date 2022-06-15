int identificado = 0;
int intentos = 0;

void stateReconocerUsuario(){
  if(machine.executeOnce){
    Serial.println("State 4");
    SPI.begin();        //Iniciamos el Bus SPI
    mfrc522.PCD_Init(); // Iniciamos el MFRC522
    Serial.println("Control de acceso, coloca la tarjeta RFID: ");
  }
// Revisamos si hay nuevas tarjetas  presentes
  if( mfrc522.PICC_IsNewCardPresent()){  
      //Seleccionamos una tarjeta
    if ( mfrc522.PICC_ReadCardSerial()) {
      // Enviamos serialemente su UID
      Serial.print("UID:");
      for (byte i = 0; i < mfrc522.uid.size; i++) {
              Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
              Serial.print(mfrc522.uid.uidByte[i], HEX);   
      } 
      Serial.println();
      // Terminamos la lectura de la tarjeta  actual
      mfrc522.PICC_HaltA();
      identificado = 1;
    }      
  }
}


bool transitionS4S5(){
  if(identificado == 1 && input == '5' or input == '8'){
    identificado = 0;
    return true;
  }else
    return false;
}

bool transitionS4S6(){
 if(input == '6'){
  alarmas = 'B';
  return true;
 }else{
  return false;
 }
}

bool transitionS4S7(){
  if(identificado == 1 && input == '7' or input == '9'){
    identificado = 0;
    return true;
  }else
    return false;
}
