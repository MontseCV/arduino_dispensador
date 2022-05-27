//Librerias
#include <StateMachine.h>
#include <SoftwareSerial.h>
#include <DHT.h>
#include <SPI.h>
#include <MFRC522.h>
// RELAY
#define RELAY_ON 0    
#define RELAY_OFF 1
//NFC 
#define RST_PIN  5    //Pin 5 para el reset del RC522
#define SS_PIN  53   //Pin 53 para el SS (SDA) del RC522
//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(11, 10); //SIM800L Tx & Rx is connected to Arduino #3 & #2

MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;


//variables generales
const int STATE_DELAY = 1000;
char input;
String nom = "Arduino";

//Variables motores
const int dirPin = 9;
const int stepPin = 8;
const int dirPin2 = 7;
const int stepPin2 = 6;
const int switchArriba = 29; //2 
const int switchAbajo = 30;  //3
const int switchBase = 4; //4
const int enableBase = 2;  //29
const int enableCremallera = 3;  //30
const int valvula = 31;
int stepDelay = 10;
int stepDelay2 = 15;
const int boton = 28;
char compartimentos;
char compart;
int dosis = 0;
int steps;
int cont = 0;
int Pdispensadas;

//Variables sensor de temperatura
int sensor = 22; 
int ventilador = 24; 
int temp, humedad;
DHT dht (sensor, DHT11);

//Variables solenoide y switch
int solenoide = 25; 
int switchPuerta = 26; 

//Variables alarma
int buzzer = 27;
int h = 0;
char alarmas;
int cas1 = 0;
int cas2 = 0;


//Declarar estados
StateMachine machine = StateMachine();

State* S0 = machine.addState(&state0); 
State* S1 = machine.addState(&stateMoverMotores);
State* S2 = machine.addState(&stateComprobarT);
State* S3 = machine.addState(&stateRegistrarNFC);
State* S4 = machine.addState(&stateReconocerUsuario);
//State* S5 = machine.addState(&stateEliminarUsuario);
State* S6 = machine.addState(&stateActivarMotores);
State* S7 = machine.addState(&stateMandarAlarma);
State* S8 = machine.addState(&stateGirarBase);
State* S9 = machine.addState(&stateACPuerta);

void setup() {
  while(!Serial){
    ;
  }
  Serial.begin(9600);
  mySerial.begin(9600);
//Inicialización del NFC -- quitar comentarios
//  SPI.begin();        //Iniciamos el Bus SPI
//  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("Iniciando...");
  
// Pines para los motores
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(switchBase, INPUT_PULLUP);
  pinMode(switchArriba,INPUT_PULLUP);
  pinMode(switchAbajo,INPUT_PULLUP);
  pinMode(enableBase, OUTPUT);
  pinMode(enableCremallera, OUTPUT);
  digitalWrite(valvula, OUTPUT);
  pinMode(boton,INPUT_PULLUP);
  digitalWrite(enableBase, LOW);
  digitalWrite(enableCremallera, LOW);
  digitalWrite(valvula, LOW);

//Pines sensor de temperatura y ventiladores
  dht.begin();
  pinMode(ventilador, OUTPUT);
  digitalWrite (ventilador, HIGH);

//Pines para el relay del solenoide
  pinMode(switchPuerta, INPUT_PULLUP);
  pinMode(solenoide, OUTPUT);
  digitalWrite (solenoide, HIGH);

//Pines buzzer
  digitalWrite(buzzer, LOW);
  
//Transiciones a estados
  S0->addTransition(&transitionS0S1,S1);  // Transición inicio a mover motores
  S1->addTransition(&transitionS1S2,S2);  // Comprobar temperatura
  S2->addTransition(&transitionS2S3,S3);  // Se requiere registrar NFC
  S2->addTransition(&transitionS2S4,S4);  // Transición a reconocer usuario
//  S2->addTransition(&transitionS2S5,S5);  // Se requiere eliminar usuario
  S2->addTransition(&transitionS2S7,S7);  // Horario listo  
  S3->addTransition(&transitionS3S2,S2);  // Vuelve a comprobar temperatura
  S4->addTransition(&transitionS4S6,S6);  // Transición a dispensar
  S4->addTransition(&transitionS4S8,S8);  // Rellenar compartimentos
  S4->addTransition(&transitionS4S7,S7);  // 3 intentos fallidos, mandar alarma
//  S5->addTransition(&transitionS5S2,S2);  // Vuelve a comprobar temperatura
  S6->addTransition(&transitionS6S7,S7);  // Transición a mandar alarma después de dispensar
  S7->addTransition(&transitionS7S0,S0);  // Volver a inicio
  S7->addTransition(&transitionS7S4,S4);  // Activar reconocimiento
  S8->addTransition(&transitionS8S9,S9);  // Abrir y cerrar puerta
  S9->addTransition(&transitionS9S0,S0);  // Volver a inicio
}

void loop() {
  machine.run();
  delay(STATE_DELAY);
  
  if(Serial.available() >0){
    input = Serial.read();
  }
  Serial.flush();
  
  
//  readSerialPort();
//  if (input != 0) {
//   sendData();
//  }
//  delay(500);
}

//Comunicacion con raspberry
//void readSerialPort() {
// input = 0;
// if (Serial.available()) {
//   delay(10);
//   while (Serial.available() > 0) {
//     input = Serial.read();
//   }
//   Serial.flush();
// }
//}

// void sendData() {
// //write data
// Serial.print(nom);
// Serial.print(" received : ");
// Serial.print(input);
//}
