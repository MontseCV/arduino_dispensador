void stateActivarVentiladores(){
  if(machine.executeOnce){
  Serial.println("State3");
  Serial.println("Activando ventiladores");
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
//  digitalWrite (ventilador1, LOW);
//  digitalWrite (ventilador2, LOW);
//  Serial.print("Ventilador activo. Temperatura: ");
//  Serial.print(temp);
//  Serial.print(" ºC ");
//  delay(2000);
}

bool transitionS3S2(){
  return true;
  
//  if(temp < 20){
//  return true;
//  }else
//  return false;
}
