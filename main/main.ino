//Librerias
#include <StateMachine.h>
#include <DHT.h>
#include <SPI.h>
#include <MFRC522.h>
// RELAY
#define RELAY_ON 0    
#define RELAY_OFF 1
//NFC 
#define RST_PIN  5    //Pin 5 para el reset del RC522
#define SS_PIN  53   //Pin 53 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;

//*************************** variables generales ***************************
const int STATE_DELAY = 1000;
int input;
String nom = "Arduino";

//************************* Variables motores *********************************
const int dirPin = 9;
const int stepPin = 6;
const int dirPin2 = 7;
const int stepPin2 = 8;
const int switchArriba = 2; 
const int switchAbajo = 3; 
const int switchBase = 4;
const int enableBase = 29;
const int enableCremallera = 30;
int stepDelay = 10;
int stepDelay2 = 15;
const int boton = 28;
char compartimentos;
int dosis = 0;
int steps;
int cont = 0;
int Pdispensadas;

//***************** Variables sensor de temperatura*******************************
int sensor = 22; 
int ventilador = 24; 
int temp, humedad;
DHT dht (sensor, DHT11);

//Variables solenoide y switch
int solenoide = 25; //A6
int switchPuerta = 26; //A7

//Variables alarma
int buzzer = 27;
int h = 0;
char alarmas;


//Declarar estados
StateMachine machine = StateMachine();

State* S0 = machine.addState(&state0); 
State* S1 = machine.addState(&stateMoverMotores);
State* S2 = machine.addState(&stateComprobarT);
State* S3 = machine.addState(&stateActivarVentiladores);
State* S4 = machine.addState(&stateRegistrarNFC);
State* S5 = machine.addState(&stateReconocerUsuario);
State* S6 = machine.addState(&stateEliminarUsuario);
State* S7 = machine.addState(&stateActivarMotores);
State* S8 = machine.addState(&stateMandarAlarma);
State* S9 = machine.addState(&stateGirarBase);
State* S10 = machine.addState(&stateACPuerta);


void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando...");

//Inicialización del NFC -- quitar comentarios
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos el MFRC522

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
  pinMode(boton,INPUT_PULLUP);
  digitalWrite(enableBase, LOW);
  digitalWrite(enableCremallera, LOW);

//Pines sensor de temperatura y ventiladores
  dht.begin();
  pinMode(ventilador, OUTPUT);
  digitalWrite (ventilador, HIGH);

//Pines para el relay del solenoide
  pinMode(switchPuerta, INPUT_PULLUP);
  pinMode(solenoide, OUTPUT);
  digitalWrite (solenoide, LOW);

//Pines buzzer
  digitalWrite(A1, LOW);
  
//Transiciones a estados
  S0->addTransition(&transitionS0S1,S1);  // Transición inicio a mover motores
  S1->addTransition(&transitionS1S2,S2);  // Comprobar temperatura
  S2->addTransition(&transitionS2S3,S3);  // Activa los ventiladores cuando temp >= 20
  S2->addTransition(&transitionS2S4,S4);  // Se requiere registrar NFC
  S2->addTransition(&transitionS2S5,S5);  // Transición a reconocer usuario
  S2->addTransition(&transitionS2S6,S6);  // Se requiere eliminar usuario  
  S3->addTransition(&transitionS3S2,S2);  // temp < 20
  S4->addTransition(&transitionS4S2,S2);  // Vuelve a comprobar temperatura
  S5->addTransition(&transitionS5S7,S7);  // Transición a dispensar
  S5->addTransition(&transitionS5S9,S9);  // Rellenar compartimentos
  S5->addTransition(&transitionS5S8,S8);  // 3 intentos fallidos, mandar alarma
  S6->addTransition(&transitionS6S2,S2);  // Vuelve a comprobar temperatura
  S7->addTransition(&transitionS7S8,S8);  // Transición a mandar alarma después de dispensar
  S8->addTransition(&transitionS8S0,S0);  // Volver a inicio
  S9->addTransition(&transitionS9S10,S10);  // Abrir y cerrar puerta
  S10->addTransition(&transitionS10S0,S0);  // Volver a inicio
}

void loop() {
  if(Serial.available() >0){
    input = Serial.read();
  }
  machine.run();
  delay(STATE_DELAY);
  
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
