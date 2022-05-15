void stateActivarVentiladores(){
  if(machine.executeOnce){
  Serial.println("State3");
  Serial.println("Activando ventiladores");
  }

//  humedad = dht.readHumidity();
//  temp = dht.readTemperature();
//  delay(100);
//  digitalWrite (ventilador, LOW);
//  Serial.println("Ventilador activo. Temperatura: ");
//  Serial.print("Temperatura: ");
//  Serial.print(temp);
//  Serial.print("ºC Humedad: ");
//  Serial.print(humedad);
//  Serial.println("%");
//  delay(2000);
}

bool transitionS3S2(){
 // return true;
//  if(temp < 29){
//   return true;
//  }else
//    return false;
return true;
}
