int registrado = 0;

void stateRegistrarNFC(){
  if(machine.executeOnce){
  Serial.println("State3");
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("Inserte la tarjeta.");
  }
// Revisamos si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()){  
     //Seleccionamos una tarjeta
    if ( mfrc522.PICC_ReadCardSerial()){
      // Enviamos serialemente su UID
      Serial.print("UID:");
      for (byte i = 0; i < mfrc522.uid.size; i++) {
              Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
              Serial.print(mfrc522.uid.uidByte[i], HEX);   
      } 
      Serial.println();
      // Terminamos la lectura de la tarjeta  actual
      mfrc522.PICC_HaltA();
      registrado = 1;       
    }      
  }
}

bool transitionS3S2(){
  if(registrado == 1){
    registrado = 0;
    return true;
  }else{
    return false;
  }
}
