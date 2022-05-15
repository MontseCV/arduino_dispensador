int registrado = 0;
void stateRegistrarNFC(){
  if(machine.executeOnce){
  Serial.println("State4");
  Serial.println("Coloca la tarjeta RFID:");
  }
  // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
//  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
//  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
//  if ( ! mfrc522.PICC_IsNewCardPresent()) {
//  return;
//  }
//  if ( ! mfrc522.PICC_ReadCardSerial()) {
//  return;
//  }
//  Serial.setTimeout(20000L);
//  byte block = 4;
//  byte buffr[] = {0x75,0x73,0x75,0x61,
//                  0x72,0x69,0x6F,0x44,
//                  0x69,0x73,0x70,0x20,
//                  0x20,0x20,0x20,0x20};
//  writeBytesToBlock(block, buffr);  
//  Serial.println(" ");
//  mfrc522.PICC_HaltA();
//  mfrc522.PCD_StopCrypto1();
//}
//
//void writeBytesToBlock(byte block, byte buff[]) {
//  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
//  if (status != MFRC522::STATUS_OK) {
//    Serial.print(F("PCD_Authenticate() failed: "));
//    Serial.println(mfrc522.GetStatusCodeName(status));
//    return;
//  }
//  else 
//    Serial.println(F("PCD_Authenticate() success: "));
//    // Write block
//    status = mfrc522.MIFARE_Write(block, buff, 16);
//  if (status != MFRC522::STATUS_OK) {
//    Serial.print(F("MIFARE_Write() fallo: "));
//    Serial.println(mfrc522.GetStatusCodeName(status));
//  return;
//  }
//  else{
//    Serial.println(F("MIFARE_Write() exitoso: "));
//    Serial.println(F("Retira la tarjeta."));
//    registrado = 1;
//  }
}

bool transitionS4S2(){
  return true;
//  if(registrado == 1){
//    registrado = 0;
//  return true;
//  }else
//  return false;
}
