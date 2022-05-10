int duracion=250; //Duración del sonido
int fMin=2000; //Frecuencia más baja que queremos emitir
int fMax=4000; //Frecuencia más alta que queremos emitir
int i=0;

void stateMandarAlarma() {
  if(machine.executeOnce){
    Serial.println("State 8");
    Serial.println("*Alarma");
  }
  if(input == 'A' or input == 'B' or input == 'C' or input == 'D'){
    alarmas = input;
  }
  switch(alarmas){
  case 'A':
    Serial.println("Se han dispensado los medicamentos");
    //generar tono de 440Hz durante 1000 ms
    if(alarmas == 'A'){
      tone(buzzer, 440, 1000);
      delay(500);
      //detener tono durante 500ms  
      noTone(buzzer);
      delay(500);
      //generar tono de 523Hz durante 500ms, y detenerlo durante 500ms.
      tone(buzzer, 523, 500);
      delay(500);
    }  
    break;

  case 'B':
    Serial.println("No se reconoce usuario");
    if(alarmas == 'B'){
      //sonido más agudo
      for (i=fMin;i<=fMax; i++){
         tone(buzzer, i, duracion);
      }
      //sonido más grave
      for (i=fMax;i>=fMin; i--){
        tone(buzzer, i, duracion);
    }
    }
   break;

  case 'C':
    Serial.println("Quedan pocas pastillas del compartimento:");
    if(alarmas == 'C'){
      tone(buzzer,500, 1000);
      delay(500);
      tone(buzzer,550, 1000);
      delay(500);
    }
  break;
  
  case 'D':
  Serial.println("Dejar de reproducir.");
  if(alarmas == 'D'){
    noTone(buzzer);
    delay(500);
  }
  break;
  }
}

bool transitionS8S0(){
  if(alarmas == 'D'){
    alarmas = '1'; 
    return true;
  }else
    return false;
}
