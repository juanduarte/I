//encoder
#define PUSH1 4 //Encoder
//other buttons
#define PUSH2 22
#define PUSH3 23
#define PUSH4 24
#define PUSH5 25
#define PUSH6 26
#define PUSH7 27
#define PUSH8 30
#define LED1 29                 
#define LED2 28

EasyButton p1(PUSH1); //instances
EasyButton p2(PUSH2);
EasyButton p3(PUSH3);
EasyButton p4(PUSH4);
EasyButton p5(PUSH5);
EasyButton p6(PUSH6);
EasyButton p7(PUSH7);
EasyButton p8(PUSH8);

int patchSel; //global  variable
int bb2, bb3, bb4, bb5; // global vars buttons states
int mode1 = 0; // modal buttons init
int mode2 = 0;

void buttons() { // read all
  p1.read();
  p2.read();
  p3.read();
  p4.read();
  p5.read();
  p6.read();
  p7.read();
  p8.read();
  LEDS(mode1, LED2);
  LEDS(mode2, LED1);
}

//int mode3 = 0;
void setupButtons() {
  pinMode(PUSH1, INPUT);
  pinMode(PUSH2, INPUT);
  pinMode(PUSH3, INPUT);
  pinMode(PUSH4, INPUT);
  pinMode(PUSH5, INPUT);
  pinMode(PUSH6, INPUT);
  pinMode(PUSH7, INPUT);
  pinMode(PUSH8, INPUT);
  pinMode(LED1, INPUT);
  pinMode(LED2, INPUT);
  delay(25);
  p1.begin();
  p2.begin();
  p3.begin();
  p4.begin();
  p5.begin();
  p6.begin();
  p7.begin();
  p8.begin();
  delay(25);
  p1.onPressed(P1);
  p2.onPressed(P2);
  p3.onPressed(P3);
  p4.onPressed(P4);
  p5.onPressed(P5);
  p6.onPressed(P6);
  p7.onPressed(P7);
  delay(25);
  char buffer99 [5];
  sprintf(buffer99, "A%03d", 1); //first file to open
  Serial.println(buffer99);
  delay(25);
  b7 = 0 ;
  Serial.println("buttons_ready");
}

//int file_p;
bool file_ch;

void P1() {
  file_ch = true;
  //Serial.println(file_ch);
  char buffer99 [5];
  sprintf(buffer99, "A%03d", patchSel); //encoder button
  Serial.println(buffer99);
  delay(100);
  //file_ch = false;
  //Serial.println(file_ch);
}

void P2() {
  b2 = bct(b2, mode1);
  bb2 = b2;
  char buffer98 [3];
  sprintf(buffer98, "a%03d", bb2);
  Serial.println(buffer98);
}

void P3() {
  b3 = bct(b3, mode1);
  bb3 = b3;
  char buffer97 [3];
  sprintf(buffer97, "e%03d", bb3);
  Serial.println(buffer97);
}

void P4() {
  b4 = bct(b4, mode1);
  bb4 = b4;
  char buffer96 [3];
  sprintf(buffer96, "i%03d", bb4);
  Serial.println(buffer96);
}

void P5() {
  b5 = bct(b5, mode1);
  bb5 = b5;
  char buffer95 [3];
  sprintf(buffer95, "o%03d", bb5);
  Serial.println(buffer95);
}

void P6() {
  b6 = modes(b6);
  mode1 = b6;
  char buffer94 [3];
  sprintf(buffer94, "u%03d", b6);
  Serial.println(buffer94);
}

void P7() {
  b7 = modes(b7);
  mode2 = b7;
  char buffer93 [3];
  sprintf(buffer93, "w%03d", b7);
  Serial.println(buffer93);
}

void LEDS(int mode, int pin){
  int t = millis()%500;
  if(mode == 1 && t < 250 ){
    digitalWrite(pin,HIGH);
  } else if(mode == 2 && t%250 < 125){
    digitalWrite(pin,HIGH);
  }
  else {
    digitalWrite(pin,LOW);
  }
}


int bct(int bbb, int mode) {
  int abc;
  if (mode == 0) {
    bbb += 1;
    bbb = bbb % 8;
  } else if (mode == 1) {
    bbb = random(8);
  } else if (mode == 2) {
    bbb += 10;
    bbb = bbb % 50;
  }
  return bbb;
}

int modes(int bbb) {
  bbb += 1;
  bbb = bbb % 3;
  return bbb;
}


//void CVGen(int mx, int ramp) { //working alone only
//  int z;
//  int xx = millis() % ramp;
//  if (b8 == 1) {
//    xx =  xx / (ramp / 1000);
//    z = xx;
//    char buffer91 [3];
//    sprintf(buffer91, "z%03d", z);
//    Serial.println(buffer91);
//  } else if (b8 == 2 && xx < mx) {
//    z = mx;
//    char buffer91 [3];
//    sprintf(buffer91, "z%03d", z);
//    Serial.println(buffer91);
//  } else {
//    z = 0;
//    char buffer91 [3];
//    sprintf(buffer91, "z%03d", z);
//    Serial.println(buffer91);
//  }
//  //return z;
//
//}
