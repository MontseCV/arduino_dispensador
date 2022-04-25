void stateComprobarT(){
 if(machine.executeOnce){
  Serial.println("State2");
  Serial.println("Comprobando temperatura");
  }
//  if (Serial.available()>0){
//    input = Serial.read();
//  }
  
//  Serial.println("State 2");
//  humedad = dht.readHumidity();
//  temp = dht.readTemperature();
//  Serial.print("Temperatura: ");
//  Serial.print(temp);
//  Serial.print("ºC Humedad: ");
//  Serial.print(humedad);
//  Serial.println("%");
//  delay(2000);
//
//  digitalWrite (ventilador1, HIGH);
//  digitalWrite (ventilador2, HIGH);
}

bool transitionS2S3(){
  if(input == '2'){
    return true;
  }else
    return false;
  
//  if(temp >= 20)
//  {
//  return true;
//  }else
//  return false;
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
