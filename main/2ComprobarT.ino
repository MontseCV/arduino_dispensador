int senalAlarma = 0;

void stateComprobarT(){
 if(machine.executeOnce){
  Serial.println("State2");
  Serial.println("Comprobando temperatura");
  }
  humedad = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print("ºC Humedad: ");
  Serial.print(humedad);
  Serial.println("%");
  delay(500);

  if(temp >= 25){
    digitalWrite (ventilador, LOW);
    delay(500);
  }else{
    digitalWrite (ventilador, HIGH);
  }
  delay(1000);
//  while (!Serial.available() > 0);{
//    Serial.println("Ingrese cual compartimento se requiere:");
//    senalAlarma = Serial.readString().toInt();
//    Serial.println(senalAlarma);
//    delay(1000);
//  }
}

bool transitionS2S3(){
  if(input == '1')
  {
    digitalWrite (ventilador, HIGH);
    return true;
  }else
  return false;
}

bool transitionS2S4(){
  if(input == '2'){
    digitalWrite (ventilador, HIGH);
    return true;
  }else
  return false;
}

bool transitionS2S6(){
  if(input == '3' or input == '4'){
    if(input == '3'){
    alarmas = 'C';
    }else if(input == '4'){
     alarmas = 'D'; 
    }
    return true;
  }else{
    return false;
  }
}
