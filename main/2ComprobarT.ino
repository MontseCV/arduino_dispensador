void stateComprobarT(){
 if(machine.executeOnce){
  Serial.println("State2");
  Serial.println("Comprobando temperatura");
  }
//  humedad = dht.readHumidity();
//  temp = dht.readTemperature();
//  Serial.print("Temperatura: ");
//  Serial.print(temp);
//  Serial.print("ºC Humedad: ");
//  Serial.print(humedad);
//  Serial.println("%");
//  delay(2000);
//
//  digitalWrite (ventilador, HIGH);

}

bool transitionS2S3(){
  if(input == '2')
  {
    return true;
  }else
    return false;
//  if(temp >= 29)
//  {
//    return true;
//  }else
//    return false;
}

bool transitionS2S4(){
  if(input == '3')
  {
  return true;
  }else
  return false;
}

bool transitionS2S5(){
  if(input == '4')
  {
  return true;
  }else
  return false;
}

bool transitionS2S6(){
  if(input == '5')
  {
  return true;
  }else
  return false;
}

bool transitionS2S8(){
  if(input == 'F')
  {
    alarmas = 'D';
  return true;
  }else
  return false;
}
