// Created by Universitas Negeri Jakarta
#include <Servo.h>
#define pwmDA1 2
#define pwmDA2 3
#define pwmDI1 8
#define pwmDI2 9
#define pwmBA1 4
#define pwmBA2 5
#define pwmBI1 6
#define pwmBI2 7
Servo tangan;        

int pin_sensor1=A0;
int pin_sensor2=A1;
int pin_sensor3=A2;
int pin_sensor4=A3;
int pin_sensor5=A4;

int serongA;
int serongB;
int modeA;
int modeM;
int a;
int b;
int c;
int d;
int e;

int state;
int Speed = 50;

void setup()
{
  Serial.begin(9600);
  //setting pin sensor sebagai INPUT
  tangan.attach(10);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  

  pinMode(pwmDA1, OUTPUT);
  pinMode(pwmDA2, OUTPUT);
  pinMode(pwmDI1, OUTPUT);
  pinMode(pwmDI2, OUTPUT);
  pinMode(pwmBA1, OUTPUT);
  pinMode(pwmBA2, OUTPUT);
  pinMode(pwmBI1, OUTPUT);
  pinMode(pwmBI2, OUTPUT);
  tangan.write(00);                 
  delay(15);
  
}


void loop() {
  if(Serial.available() > 0){     
  state = Serial.read(); 
  Serial.println(state);

  if (state == 13){
    modeA = true;
    modeM = false;
    }
  if (state == 14) {
    modeA = false;
    modeM = true;
   }

}
a = digitalRead(A0);
b = digitalRead(A1);
c = digitalRead(A2);
d = digitalRead(A3);
e = digitalRead(A4);

//  Serial.print("A1=");
//  Serial.print(a);
//  Serial.print("A2=");
//  Serial.print(b);
//  Serial.print("A3=");
//  Serial.print(c);
//  Serial.print("A4=");
//  Serial.print(d);
//  Serial.print("A5=");
//  Serial.println(e);
Auto();
Manual();
}
void Auto()
{
  if ((a==1)&&(b==1)&&(c==0)&&(d==1)&&(e==1)&&(modeA==true))
  {forward();}
  if ((a==0)&&(b==0)&&(c==1)&&(d==0)&&(e==0)&&(modeA==true))
  {forward();}
  if ((a==1)&&(b==0)&&(c==0)&&(d==1)&&(e==1)&&(modeA==true))
  {forward();}
  if ((a==1)&&(b==1)&&(c==0)&&(d==0)&&(e==1)&&(modeA==true))
  {forward();}
  
  if ((a==1)&&(b==0)&&(c==1)&&(d==1)&&(e==1)&&(modeA==true))
  {
   analogWrite(pwmDA1, Speed );
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, Speed - 20);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed );
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, Speed - 20);
   analogWrite(pwmBI2, 0);
   }
  if ((a==0)&&(b==1)&&(c==1)&&(d==1)&&(e==1)&&(modeA==true))
  {
   analogWrite(pwmDA1, Speed + 30);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, 0);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed + 30);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, 0);
   analogWrite(pwmBI2, 0);
   }
  if ((a==0)&&(b==0)&&(c==1)&&(d==1)&&(e==1)&&(modeA==true))
  {
   analogWrite(pwmDA1, Speed + 30);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, 0);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed + 30);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, 0);
   analogWrite(pwmBI2, 0);
  }
  if ((a==0)&&(b==0)&&(c==0)&&(d==1)&&(e==1)&&(modeA==true))
  {
    analogWrite(pwmDA1, Speed + 30);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, 0);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed + 30);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, 0);
   analogWrite(pwmBI2, 0);
   }

  //BELOK KIRI 
  if ((a==1)&&(b==1)&&(c==1)&&(d==0)&&(e==1)&&(modeA==true))
  {
   analogWrite(pwmDA1, Speed - 20);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, Speed );
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed - 20);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, Speed );
   analogWrite(pwmBI2, 0);}
  if ((a==1)&&(b==1)&&(c==1)&&(d==1)&&(e==0)&&(modeA==true))
  {
   analogWrite(pwmDA1, 0);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, Speed + 30);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, 0);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, Speed + 30);
   analogWrite(pwmBI2, 0);}
  if ((a==1)&&(b==1)&&(c==1)&&(d==0)&&(e==0)&&(modeA==true))
  {
   analogWrite(pwmDA1, 0);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, Speed + 30);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, 0);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, Speed + 30);
   analogWrite(pwmBI2, 0);}
  if ((a==1)&&(b==1)&&(c==0)&&(d==0)&&(e==0)&&(modeA==true))
  {
   analogWrite(pwmDA1, 0);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, Speed + 30);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, 0);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, Speed + 30);
   analogWrite(pwmBI2, 0);}
 
  if ((a==0)&&(b==0)&&(c==0)&&(d==0)&&(e==0)&&(modeA==true))
  {Stop();}
  //if ((a==1)&&(b==1)&&(c==1)&&(d==1)&&(e==1)&&(modeA==true))
  //{Stop();}
}


void Manual(){
   if(state > 20){
     Speed = state;} 

     // if the state is '1' the DC motor will go forward
   if ((state == 1) &&(modeM==true)){
    maju();
    }

   // if the state is '2' the motor will Reverse
   else if ((state == 2) &&(modeM==true)){
    mundur();
    }
    
   // if the state is '3' the motor will turn left
   else if ((state == 3) &&(modeM==true)){kiri();}
    
   // if the state is '4' the motor will turn right
   else if ((state == 4) &&(modeM==true)){kanan();}

   // if the state is '4' the motor will turn right
   else if ((state == 5) &&(modeM==true)){
   analogWrite(pwmDA1, Speed -20);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, Speed );
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed -20);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, Speed );
   analogWrite(pwmBI2, 0);
   }

   // if the state is '4' the motor will turn right
   else if ((state == 6) &&(modeM==true)){ 
   analogWrite(pwmDA1, Speed );
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, Speed -20);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed );
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, Speed -20);
   analogWrite(pwmBI2, 0);
   }

   // if the state is '4' the motor will turn right
   else if ((state == 7) &&(modeM==true)){mundur_serong_kanan();}

   // if the state is '4' the motor will turn right
   else if ((state == 8) &&(modeM==true)){mundur_serong_kiri();}

   // if the state is '3' the motor will turn left
   else if ((state == 9) &&(modeM==true)){putar_kiri();}

   // if the state is '3' the motor will turn left
   else if ((state == 10) &&(modeM==true)){putar_kanan();}
    
   // if the state is '0' the motor will Stop
   else if ((state == 0) &&(modeM==true)) {Stop();}

   // if the state is '0' the motor will Stop
   else if ((state == 11) &&(modeM==true)) {salam();}

   // if the state is '0' the motor will Stop
   else if ((state == 12) &&(modeM==true)) {unsalam();}
  }


void forward()
{
   analogWrite(pwmDA1, Speed);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, Speed);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, Speed);
   analogWrite(pwmBI2, 0);
}

void maju (){
   analogWrite(pwmDA1, Speed);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, Speed);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, Speed);
   analogWrite(pwmBI2, 0);
}

void mundur(){
   analogWrite(pwmDA1, 0);
   analogWrite(pwmDA2, Speed);
   analogWrite(pwmDI1, 0);
   analogWrite(pwmDI2, Speed);
   analogWrite(pwmBA1, 0);
   analogWrite(pwmBA2, Speed);
   analogWrite(pwmBI1, 0);
   analogWrite(pwmBI2, Speed);
}

void kanan (){
   analogWrite(pwmDA1, 0);
   analogWrite(pwmDA2, Speed);
   analogWrite(pwmDI1, Speed);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, 0);
   analogWrite(pwmBI2, Speed);
}
void kiri (){
   analogWrite(pwmDA1, Speed);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, 0);
   analogWrite(pwmDI2, Speed);
   analogWrite(pwmBA1, 0);
   analogWrite(pwmBA2, Speed);
   analogWrite(pwmBI1, Speed);
   analogWrite(pwmBI2, 0);
}
void maju_serong_kanan (){
   analogWrite(pwmDA1, 0);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, Speed);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, Speed);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, 0);
   analogWrite(pwmBI2, 0);
}
void maju_serong_kiri (){
   analogWrite(pwmDA1, Speed);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, 0);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, 0);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, Speed);
   analogWrite(pwmBI2, 0);
}
void mundur_serong_kanan (){
   analogWrite(pwmDA1, 0);
   analogWrite(pwmDA2, Speed);
   analogWrite(pwmDI1, 0);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, 0);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, 0);
   analogWrite(pwmBI2, Speed);
}
void mundur_serong_kiri (){
   analogWrite(pwmDA1, 0);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, 0);
   analogWrite(pwmDI2, Speed);
   analogWrite(pwmBA1, 0);
   analogWrite(pwmBA2, Speed);
   analogWrite(pwmBI1, 0);
   analogWrite(pwmBI2, 0);
}
void putar_kanan (){
   analogWrite(pwmDA1, 0);
   analogWrite(pwmDA2, Speed -30);
   analogWrite(pwmDI1, Speed -30);
   analogWrite(pwmDI2, 0);
   analogWrite(pwmBA1, 0);
   analogWrite(pwmBA2, Speed - 30);
   analogWrite(pwmBI1, Speed - 30);
   analogWrite(pwmBI2, 0);
}
void putar_kiri (){
   analogWrite(pwmDA1, Speed- 30);
   analogWrite(pwmDA2, 0);
   analogWrite(pwmDI1, 0);
   analogWrite(pwmDI2, Speed - 30);
   analogWrite(pwmBA1, Speed - 30);
   analogWrite(pwmBA2, 0);
   analogWrite(pwmBI1, 0);
   analogWrite(pwmBI2, Speed - 30);
}

void salam (){
  tangan.write(60);
}

void unsalam (){
  tangan.write(00);
}

void Stop()
{
  analogWrite(pwmDA1, 0);
  analogWrite(pwmDA2, 0);
  analogWrite(pwmDI1, 0);
  analogWrite(pwmDI2, 0);
  analogWrite(pwmBA1, 0);
  analogWrite(pwmBA2, 0);
  analogWrite(pwmBI1, 0);
  analogWrite(pwmBI2, 0);
}
