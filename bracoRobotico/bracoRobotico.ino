#include <Servo.h>
#define ANGULO_INICIAL_MOTOR 90

// --- Mapeamento dos Joysticks ---
#define joystick1X A0
#define joystick1Y A1
#define joystick2X A2
#define joystick2Y A3


// --- Mapeamento dos Servos ---
Servo motorBase;
Servo motorBraco1; //antigo m1
Servo motorBraco2; //antigo m2
Servo motorGarra;

// --- Inicializacao ---
void setup() {
  mapearPinosDosMotores();
  inicializarAngulosDosMotores();
  mapearJoystickComoInput(); 
}

// --- Loop Infinito ---
void loop() {

 moverBase();
 moverBraco1();
 moverBraco2();
 moverGarra();
 delay(100);
    
}

// --- Funcoes Auxiliares ---

// --- Mapear Pinos dos Servos Motores ---
void mapearPinosDosMotores(){
  motorBase.attach(5);
  motorBraco1.attach(6);
  motorBraco2.attach(9);
  motorGarra.attach(10);
}

// --- Inicializar Angulos iniciais dos Motores ---
void inicializarAngulosDosMotores(){
  motorBase.write(ANGULO_INICIAL_MOTOR);
  motorBraco1.write(ANGULO_INICIAL_MOTOR);
  motorBraco2.write(ANGULO_INICIAL_MOTOR);
  motorGarra.write(ANGULO_INICIAL_MOTOR);
}

// --- Mapear Pinos do Joystick como INPUT ---
void mapearJoystickComoInput(){
  pinMode(joystick1X, INPUT);
  pinMode(joystick1Y, INPUT);
  pinMode(joystick2X, INPUT);
  pinMode(joystick2Y, INPUT); 
}

// --- Mover Baser ---
void moverBase(){
   int posX = analogRead(joystick1X);
  posX = map(posX, 0, 1023, 0, 180); //aqui a mágica acontece
  motorBase.write(posX);
}

// --- Mover Braco 1 ---
void moverBraco1(){
  int posY = analogRead(joystick1Y);
  posY = map(posY, 0, 1023, 35, 120); //aqui a mágica acontece
  motorBraco1.write(posY);
}

// --- Mover Braco 2 ---
void moverBraco2(){
  int posX = analogRead(joystick2X);
  posX = map(posX, 0, 1023, 50, 120); //aqui a mágica acontece
  motorBraco2.write(posX);
}

// --- Mover Garra ---
void moverGarra(){
  int posY = analogRead(joystick2Y);
  posY = map(posY, 0, 1023, 70, 140); //aqui a mágica acontece
  motorGarra.write(posY);
}
