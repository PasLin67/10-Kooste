#define POT A0 // Potikan keskijalka A0 pinniin
                    // Uloimmat jalat GND ja +5V pinnit
#define NAPPI 2 // Painike liitetty pinniin D2 ja GND
#define SEGA 6
#define SEGB 7
#define SEGC 9
#define SEGD 10
#define SEGE 11
#define SEGF 5
#define SEGG 4
#define SEGDP 8
#define LEDON LOW
#define LEDOFF HIGH
#define PRESSED LOW
#define RELEASED HIGH
int NAPPIState = 0;
int lukema = 0;
 
void setup() {
  pinMode(SEGA, OUTPUT); //6
  pinMode(SEGB, OUTPUT); //7
  pinMode(SEGC, OUTPUT); //9
  pinMode(SEGD, OUTPUT); //10
  pinMode(SEGE, OUTPUT); //11
  pinMode(SEGF, OUTPUT); //5
  pinMode(SEGG, OUTPUT); //4
  pinMode(SEGDP, OUTPUT); //8
  pinMode(NAPPI, INPUT_PULLUP);
  NAPPIState = digitalRead(NAPPI);
}

void num0(){
  digitalWrite(SEGA, LEDON);
  digitalWrite(SEGB, LEDON);
  digitalWrite(SEGC, LEDON);
  digitalWrite(SEGD, LEDON);
  digitalWrite(SEGE, LEDON);
  digitalWrite(SEGF, LEDON);
  digitalWrite(SEGG, LEDOFF);
  digitalWrite(SEGDP, LEDON);
}
void num1(){
  digitalWrite(SEGA, LEDOFF);
  digitalWrite(SEGB, LEDON);
  digitalWrite(SEGC, LEDON);
  digitalWrite(SEGD, LEDOFF);
  digitalWrite(SEGE, LEDOFF);
  digitalWrite(SEGF, LEDOFF);
  digitalWrite(SEGG, LEDOFF);
  digitalWrite(SEGDP, LEDON);
}
void num2(){
  digitalWrite(SEGA, LEDON);
  digitalWrite(SEGB, LEDON);
  digitalWrite(SEGC, LEDOFF);
  digitalWrite(SEGD, LEDON);
  digitalWrite(SEGE, LEDON); 
  digitalWrite(SEGF, LEDOFF);
  digitalWrite(SEGG, LEDON); 
  digitalWrite(SEGDP,LEDON);
}
void num3(){
  digitalWrite(SEGA, LEDON);
  digitalWrite(SEGB, LEDON);
  digitalWrite(SEGC, LEDON); 
  digitalWrite(SEGD, LEDON);
  digitalWrite(SEGE, LEDOFF);
  digitalWrite(SEGF, LEDOFF);
  digitalWrite(SEGG, LEDON);
  digitalWrite(SEGDP, LEDON);
}
void num4(){
  digitalWrite(SEGA, LEDOFF);
  digitalWrite(SEGB, LEDON);
  digitalWrite(SEGC, LEDON);
  digitalWrite(SEGD, LEDOFF);
  digitalWrite(SEGE, LEDOFF);
  digitalWrite(SEGF, LEDON);
  digitalWrite(SEGG, LEDON);
  digitalWrite(SEGDP, LEDON);
}
void num5(){
  digitalWrite(SEGA, LEDON);
  digitalWrite(SEGB, LEDOFF);
  digitalWrite(SEGC, LEDON);
  digitalWrite(SEGD, LEDON);
  digitalWrite(SEGE, LEDOFF);
  digitalWrite(SEGF, LEDON);
  digitalWrite(SEGG, LEDON);
  digitalWrite(SEGDP, LEDON);
}
void num6(){
  digitalWrite(SEGA, LEDON);
  digitalWrite(SEGB, LEDOFF);
  digitalWrite(SEGC, LEDON);
  digitalWrite(SEGD, LEDON);
  digitalWrite(SEGE, LEDON);
  digitalWrite(SEGF, LEDON);
  digitalWrite(SEGG, LEDON);
  digitalWrite(SEGDP, LEDON);
}
void num7(){
  digitalWrite(SEGA, LEDON);
  digitalWrite(SEGB, LEDON);
  digitalWrite(SEGC, LEDON); 
  digitalWrite(SEGD, LEDOFF);
  digitalWrite(SEGE, LEDOFF);
  digitalWrite(SEGF, LEDOFF);
  digitalWrite(SEGG, LEDOFF);
  digitalWrite(SEGDP, LEDON);
}
void num8(){
  digitalWrite(SEGA, LEDON);
  digitalWrite(SEGB, LEDON);
  digitalWrite(SEGC, LEDON);
  digitalWrite(SEGD, LEDON);
  digitalWrite(SEGE, LEDON);
  digitalWrite(SEGF, LEDON);
  digitalWrite(SEGG, LEDON);
  digitalWrite(SEGDP, LEDON);
}
void num9(){
  digitalWrite(SEGA, LEDON);
  digitalWrite(SEGB, LEDON);
  digitalWrite(SEGC, LEDON);
  digitalWrite(SEGD, LEDON);
  digitalWrite(SEGE, LEDOFF);
  digitalWrite(SEGF, LEDON);
  digitalWrite(SEGG, LEDON);
  digitalWrite(SEGDP, LEDON);
}

void showNum(int num){
  switch(num){
    case 0:num0(); break;
    case 1:num1(); break;
    case 2:num2(); break;
    case 3:num3(); break;
    case 4:num4(); break;
    case 5:num5(); break;
    case 6:num6(); break;
    case 7:num7(); break;
    case 8:num8(); break;
    case 9:num9(); break;
   }
}
int buttonPressed(){
  int x = digitalRead(NAPPI);
  lukema = analogRead(POT);
  int ret = 0;
  if(x == PRESSED && NAPPIState == RELEASED){
    ret = 1;
   }
   NAPPIState = x;
   return ret;
}



   
int getNum(){
  int i = lukema;
  if(i < 1){
    return 0;
  }
  if(i < 16){
    return 1;
  }
  if(i < 32){
    return 2;
  }
  if(i < 54){
    return 3;
  }
  if(i < 86){
    return 4;
  }
  if(i < 127){
    return 5;
  }
  if(i < 256){
    return 6;
  }
  if(i < 512){
    return 7;
  }
  if(i < 752){
    return 8;
  }
    return 9;
   
  }
  



void loop() {
  if(buttonPressed()){
  
     showNum(getNum());
  
  }
}

