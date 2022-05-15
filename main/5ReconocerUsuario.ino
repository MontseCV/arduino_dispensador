int identificado = 0;
int intentos = 0;

void stateReconocerUsuario(){
  if(machine.executeOnce){
    Serial.println("State 5");
    Serial.println("Control de acceso, coloca la tarjeta RFID: ");
  }
  // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
//  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
//  byte block;
//  byte len;
//  //-------------------------------------------
//  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
//  if ( ! mfrc522.PICC_IsNewCardPresent()) {
//    return;
//  }
//  // Selecciona una de las tarjetas
//  if ( ! mfrc522.PICC_ReadCardSerial()) {
//    return;
//  }
//  Serial.println(F("*Tarjeta detectada*"));
//  byte buffer1[18];
//  block = 4;
//  len = 18;
//  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(mfrc522.uid));
//  
//  if (status != MFRC522::STATUS_OK) {
//    Serial.print(F("Fallo de autenticacion."));
//    Serial.println(mfrc522.GetStatusCodeName(status));
//    return;
//  }
//  status = mfrc522.MIFARE_Read(block, buffer1, &len);
//  if (status != MFRC522::STATUS_OK) {
//    Serial.print(F("Fallo de lectura."));
//    Serial.println(mfrc522.GetStatusCodeName(status));
//    return;
//  }
//  String value = " ";
//  for (uint8_t i = 0; i < 16; i++)
//  {
//    value += (char)buffer1[i];
//  }
//  value.trim();
//  if(value == "usuarioDisp"){
//    Serial.println("Informacion correcta.");
//    identificado = 1;
//  }else{
//    Serial.println("Informacion incorrecta.");
//    intentos++;
//  }
//  Serial.print(value);
//  Serial.println(F("\n*Fin de la lectura, puede retirar la tarjeta.*\n"));
//  delay(1000);
//  mfrc522.PICC_HaltA();
//  mfrc522.PCD_StopCrypto1();
}


bool transitionS5S7(){
  if(input == '6')
  {
    return true;
  }else
    return false;
//  if(identificado == 1 && input == '6'){
//    identificado = 0;
//    return true;
//  }else
//    return false;
}

bool transitionS5S9(){
  if(input == '7')
  {
    return true;
  }else
    return false;
//    if(identificado == 1 && input == '7'){
//    return true;
//  }else
//    return false;
}

bool transitionS5S8(){
  if(input == '8')
  {
    return true;
  }else
    return false;
//   if(intentos == 3){
//    intentos = 0;
//    alarmas = 'B';
//    return true;
//  }else
//    return false;
}
