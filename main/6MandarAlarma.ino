int duracion=250; //Duración del sonido
int fMin=2000; //Frecuencia más baja que queremos emitir
int fMax=4000; //Frecuencia más alta que queremos emitir
int i=0;
int veces = 0;
String numero;

void stateMandarAlarma() {
  if(machine.executeOnce){
    Serial.println("State 7");
    Serial.println("*Alarma");
  }
  if(input == 'A' or input == 'B' or input == 'C' or input == 'D' or input == 'E'){
    alarmas = input;
  }
  
  switch(alarmas){
  // Caso A: se han dispensado los medicamentos
  case 'A':
  if(alarmas == 'A'){
    Serial.println("Se han dispensado los medicamentos.");
    if(machine.executeOnce){
        while(numero.length() == 0){
          Serial.println("Ingrese numero:");
          numero = Serial.readString();
          numero.trim();
     }
      Enviar_msj(numero, "Tome sus medicamentos del dispensador.");
    }    
    for(veces = 0; veces < 4; veces++){
    //generar tono de 440Hz durante 1000 ms
    tone(buzzer, 440, 1000);
    delay(500);
    //detener tono durante 500ms  
    noTone(buzzer);
    delay(500);
    //generar tono de 523Hz durante 500ms, y detenerlo durante 500ms.
    tone(buzzer, 523, 500);
    delay(500);
    }
    cas1 = 1;
    cas2 = 0;
    alarmas = 'E';
    }  
    break;
    
  //Caso B: no se reconoce al usuario que intenta ingresar.
  case 'B':
    Serial.println("No se reconoce usuario.");
    if(alarmas == 'B'){
      if(machine.executeOnce){
        while(numero.length() == 0){
          Serial.println("Ingrese numero:");
          numero = Serial.readString();
          numero.trim();
     }
      Enviar_msj(numero, "No se ha reconocido al usuario.");
    } 
    for(veces = 0; veces < 4; veces++){
      //sonido más agudo
      for (i=fMin;i<=fMax; i++){
         tone(buzzer, i, duracion);
      }
      //sonido más grave
      for (i=fMax;i>=fMin; i--){
        tone(buzzer, i, duracion);
      }
    }
    cas1 = 1;
    cas2 = 0;
    alarmas = 'E';
    }
   break;

  //Caso C: quedan pocas pastillas en algún compartimento.
  case 'C':
    Serial.println("Quedan pocas pastillas del compartimento:");
    if(alarmas == 'C'){
      if(machine.executeOnce){
        while(numero.length() == 0){
          Serial.println("Ingrese numero:");
          numero = Serial.readString();
          numero.trim();
     }
      Enviar_msj(numero, "Quedan pocas pastillas en el compartimento."); //indicar compartimento
    } 
      tone(buzzer,500, 1000);
      delay(500);
      tone(buzzer,550, 1000);
      delay(500);
      cas1 = 1;
      cas2 = 0;
    }
  break;
  
  //Caso D: se le avisa al usuario que el horario que indicó para su medicamento ha llegado.
  case 'D':
  Serial.println("Es hora de su medicamento.");
  if(alarmas == 'D'){
    if(machine.executeOnce){
        while(numero.length() == 0){
          Serial.println("Ingrese numero:");
          numero = Serial.readString();
          numero.trim();
     }
      Enviar_msj(numero, "Es hora de su medicamento.");
    } 
    //generar tono de 440Hz durante 1000 ms
    tone(buzzer, 440, 1000);
    delay(500);
    //detener tono durante 500ms  
    noTone(buzzer);
    delay(500);
    //generar tono de 523Hz durante 500ms, y detenerlo durante 500ms.
    tone(buzzer, 523, 500);
    delay(500);
    cas1 = 0;
    cas2 = 1;
  }
  break;

  //Caso E: dejar de reproducir.
  case 'E':
  Serial.println("Dejar de reproducir.");
  if(alarmas == 'E'){
    noTone(buzzer);
    delay(500);
  }
  break;
 }

}

void Enviar_msj(String numero, String msj)
{
  //Se establece el formato de SMS en ASCII
  String config_numero = "AT+CMGS=\"+52" + numero + "\"\r\n";
  Serial.println(config_numero);

  //configurar modulo como modo SMS
  mySerial.write("AT+CMGF=1\r\n");
  delay(1000);
  
  //Enviar comando para un nuevos SMS al numero establecido
  mySerial.print(config_numero);
  delay(1000);

  //Enviar contenido del SMS
  mySerial.print(msj);
  delay(1000);

  //Enviar Ctrl+Z
  mySerial.write((char)26);
  delay(1000);
  Serial.println("Mensaje enviado");
}

bool transitionS6S0(){
  if(alarmas == 'E' && cas1 == 1){
    numero = "";
    alarmas = '1'; 
    return true;
  }else
    return false;
}

bool transitionS6S4(){
  if(alarmas == 'E' && cas2 == 1){
    numero = "";
    alarmas = '1'; 
    return true;
  }else
    return false;
}
