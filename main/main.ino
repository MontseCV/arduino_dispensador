//Librerias
#include <StateMachine.h>
#include <DHT.h>
#include <SPI.h>
#include <MFRC522.h>
// RELAY
#define RELAY_ON 0    
#define RELAY_OFF 1
//NFC  --- quitar comentarios
//#define RST_PIN  9    //Pin 9 para el reset del RC522
//#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
//MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522

//*************************** variables generales ***************************
const int STATE_DELAY = 1000;
int input;

//************************* Variables motores *********************************
//const int dirPin = 5;
//const int stepPin = 6;
//const int dirPin2 = 8;
//const int stepPin2 = 9;
//const int switchArriba = 3;
//const int switchAbajo = 4;
//const int switchBase = 7;
//const int steps = 200;
//int stepDelay = 10;
//int stepDelay2 = 15;
//int val = 0;

//***************** Variables sensor de temperatura*******************************
//int sensor = 2;
//int ventilador1 = 3;
//int ventilador2 = 4;
//int temp, humedad;
//DHT dht (sensor, DHT11);

//Variables solenoide y switch
int solenoide = 2;
int switchPuerta = 3;

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
  
// Pines para los motores
//  pinMode(dirPin, OUTPUT);
//  pinMode(stepPin, OUTPUT);
//  pinMode(dirPin2, OUTPUT);
//  pinMode(stepPin2, OUTPUT);
//  pinMode(switchArriba, INPUT_PULLUP);
//  pinMode(switchAbajo, INPUT_PULLUP);
//  pinMode(switchBase, INPUT_PULLUP);

//Pines sensor de temperatura y ventiladores
//  pinMode(ventilador1, OUTPUT);
//  pinMode(ventilador2, OUTPUT);
//  dht.begin();
//  digitalWrite (ventilador1, HIGH);
//  digitalWrite (ventilador2, HIGH);
  
//Inicialización del NFC -- quitar comentarios
//  SPI.begin();        //Iniciamos el Bus SPI
//  mfrc522.PCD_Init(); // Iniciamos el MFRC522

//Pines para el relay del solenoide
  pinMode(switchPuerta, INPUT_PULLUP);
  pinMode(solenoide, OUTPUT);
  digitalWrite (solenoide, LOW);
  
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
  if (Serial.available()>0){
    input = Serial.read();
  }
  machine.run();
  delay(STATE_DELAY);
}
