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
int valvula = 31;
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
State* S5 = machine.addState(&stateActivarMotores);
State* S6 = machine.addState(&stateMandarAlarma);
State* S7 = machine.addState(&stateGirarBase);
State* S8 = machine.addState(&stateACPuerta);

void setup() {
  while(!Serial){
    ;
  }
  Serial.begin(9600);
  mySerial.begin(9600);
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
  pinMode(valvula, OUTPUT);
  digitalWrite(valvula, HIGH);
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
  digitalWrite (solenoide, HIGH);

//Pines buzzer
  digitalWrite(buzzer, LOW);
  
//Transiciones a estados
  S0->addTransition(&transitionS0S1,S1);  // Transición inicio a mover motores
  S1->addTransition(&transitionS1S2,S2);  // Comprobar temperatura
  S2->addTransition(&transitionS2S3,S3);  // Se requiere registrar NFC
  S2->addTransition(&transitionS2S4,S4);  // Transición a reconocer usuario
  S2->addTransition(&transitionS2S6,S6);  // Alarma de horario de dosis
  S3->addTransition(&transitionS3S2,S2);  // Vuelve a comprobar temperatura
  S4->addTransition(&transitionS4S5,S5);  // Transición a dispensar
  S4->addTransition(&transitionS4S7,S7);  // Rellenar compartimentos
  S4->addTransition(&transitionS4S6,S6);  // 3 intentos fallidos, mandar alarma
  S5->addTransition(&transitionS5S6,S6);  // Transición a mandar alarma después de dispensar
  S6->addTransition(&transitionS6S0,S0);  // Volver a inicio
  S6->addTransition(&transitionS6S4,S4);  // Activar reconocimiento
  S7->addTransition(&transitionS7S8,S8);  // Abrir y cerrar puerta
  S8->addTransition(&transitionS8S0,S0);  // Volver a inicio
}

void loop() {
  machine.run();
  delay(STATE_DELAY);
  
  if(Serial.available() >0){
    input = Serial.read();
  }
  Serial.flush();
}
