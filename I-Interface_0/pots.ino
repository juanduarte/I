static const uint8_t analog_pins[12] = {A0, A2, A4, A6, A1, A3, A5, A7, A8, A10, A9, A11};

int deltaG = 2;

void set_pots() {
  potentiometers();
  for (int i = 0; i < 13; i++) { //or i <= 4
    //Serial.println(analogRead(i));
  }
}

int pot_values[12] = {k1, k2, k3, k4, k5, k6, k7, k8, k11, k12, k13, k14};

int touchSQ, touchBR;

void potentiometers() {
  int lps = millis() % 3500;
  int lapse = lps + ((touchSQ - touchBR) * 500);
  k1 = scaleO1(analog_pins[0], 100, lapse - 10);
  k2 = scaleO2(analog_pins[1], 100, lapse - 20);
  k3 = scaleO3(analog_pins[2], 100, lapse - 30);
  k4 = scaleO4(analog_pins[3], 100, lapse - 40);
  k5 = scaleO5(analog_pins[4], 100, lapse - 50);
  k6 = scaleO6(analog_pins[5], 100, lapse - 60);
  k7 = scaleO7(analog_pins[6], 100, lapse - 70);
  k8 = scaleO8(analog_pins[7], 100, lapse - 80);
  k11 = scaleI1(analog_pins[8], 100, lapse - 50);
  k12 = scaleI2(analog_pins[9], 100, lapse - 60);
  k13 = scaleI3(analog_pins[10], 100, lapse - 70);
  k14 = scaleI4(analog_pins[11], 100, lapse - 80);
}

int sc_abs(int input, int mxt, int lmt) {
  long int x;
  if (b7 == 0) {
    x = analogRead(input);
    x = map(x, 0, 1023, 0, 999);
    //current_1 = x;
  } else if (b7 == 1 && millis() % mxt < lmt) {
    x = analogRead(input);
    x = random(x);
    //current_1 = random(x);
  } else if (b7 == 2) {
    x = analogRead(input);
    if(x > 0){
    x = millis() % (x * 10);
    x = x / 10;
    x = x + random(1000)/100;
    }
  }
  return x;
}

//P1
int current_1, prev_1, delta_1;
int deltaValue_1 = deltaG;
int scaleO1(int input, int mxt, int lmt) {
  int x = sc_abs(input, mxt, lmt);
  current_1 = x;
  delta_1 = abs(prev_1 - current_1);
  if (delta_1 >= deltaValue_1) {
    print_p1(current_1);
  }
  prev_1 = current_1;
  return x;
}

void print_p1(int val) {
  char buffer21 [9];
  sprintf(buffer21, "!%03d", val);
  Serial.println(buffer21);
}

//P2

int current_2, prev_2, delta_2;
int deltaValue_2 = deltaG;

int scaleO2(int input, int mxt, int lmt) {
  int x = sc_abs(input, mxt, lmt);
  current_2 = x;
  delta_2 = abs(prev_2 - current_2);
  if (delta_2 >= deltaValue_2) {
    print_p2(current_2);
  }
  prev_2 = current_2;
  return x;
}

void print_p2(int val) {
  char buffer22 [5];
  sprintf(buffer22, "#%03d", val);
  Serial.println(buffer22);
}

//P3
int current_3, prev_3, delta_3;
int deltaValue_3 = deltaG;
int scaleO3(int input, int mxt, int lmt) {
  int x = sc_abs(input, mxt, lmt);
  current_3 = x;
  delta_3 = abs(prev_3 - current_3);
  if (delta_3 >= deltaValue_3) {
    print_p3(current_3);
  }
  prev_3 = current_3;
  return x;
}

void print_p3(int val) {
  char buffer23 [5];
  sprintf(buffer23, "$%03d", val);
  Serial.println(buffer23);
}

//P4
int current_4, prev_4, delta_4;
int deltaValue_4 = deltaG;

int scaleO4(int input, int mxt, int lmt) {
  int x = sc_abs(input, mxt, lmt);
  current_4 = x;
  delta_4 = abs(prev_4 - current_4);
  if (delta_4 >= deltaValue_4) {
    print_p4(current_4);
  }
  prev_4 = current_4;
  return x;
}
void print_p4(int val) {
  char buffer24 [5];
  sprintf(buffer24, ".%03d", val);
  Serial.println(buffer24);
}

//P5
int current_5, prev_5, delta_5;
int deltaValue_5 = deltaG;

int scaleO5(int input, int mxt, int lmt) {
  int x = sc_abs(input, mxt, lmt);
  current_5 = x;
  delta_5 = abs(prev_5 - current_5);
  if (delta_5 >= deltaValue_5) {
    print_p5(current_5);
  }
  prev_5 = current_5;
  return x;
}

void print_p5(int val) {
  char buffer25 [5];
  sprintf(buffer25, "&%03d", val);
  Serial.println(buffer25);
}

//P6

int current_6, prev_6, delta_6;
int deltaValue_6 = deltaG;

int scaleO6(int input, int mxt, int lmt) {
  int x = sc_abs(input, mxt, lmt);
  current_6 = x;
  delta_6 = abs(prev_6 - current_6);
  if (delta_6 >= deltaValue_6) {
    print_p6(current_6);
  }
  prev_6 = current_6;
  return x;
}

void print_p6(int val) {
  char buffer26 [5];
  sprintf(buffer26, "'%03d", val);
  Serial.println(buffer26);
}

//P7

int current_7, prev_7, delta_7;
int deltaValue_7 = deltaG;

int scaleO7(int input, int mxt, int lmt) {
  int x = sc_abs(input, mxt, lmt);
  current_7 = x;
  delta_7 = abs(prev_7 - current_7);
  if (delta_7 >= deltaValue_7) {
    print_p7(current_7);
  }
  prev_7 = current_7;
  return x;
}

void print_p7(int val) {
  char buffer27 [5];
  sprintf(buffer27, "(%03d", val);
  Serial.println(buffer27);
}

//P8

int current_8, prev_8, delta_8;
int deltaValue_8 = deltaG;

int scaleO8(int input, int mxt, int lmt) {
  int x = sc_abs(input, mxt, lmt);
  current_8 = x;
  delta_8 = abs(prev_8 - current_8);
  if (delta_8 >= deltaValue_8) {
    print_p8(current_8);
  }
  prev_8 = current_8;
  return x;
}

void print_p8(int val) {
  char buffer28 [5];
  sprintf(buffer28, ")%03d", val);
  Serial.println(buffer28);
}

//P9

int current_9, prev_9, delta_9;
int deltaValue_9 = deltaG;

int scaleI1(int input, int mxt, int lmt) {
  int x;
  x = analogRead(input);
  x = map(x, 0, 1023, 999, 0);
  current_9 = x;
  delta_9 = abs(prev_9 - current_9);
  if (delta_9 >= deltaValue_9) {
    print_p9(current_9);
  }
  prev_9 = current_9;
  return x;
}

void print_p9(int val) {
  char buffer29 [5];
  sprintf(buffer29, "*%03d", val);
  Serial.println(buffer29);
}

//P10

int current_10, prev_10, delta_10;
int deltaValue_10 = deltaG;

int scaleI2(int input, int mxt, int lmt) {
  int x;
  x = analogRead(input);
  x = map(x, 0, 1023, 999, 0);
  current_10 = x;
  delta_10 = abs(prev_10 - current_10);
  if (delta_10 >= deltaValue_10) {
    print_p10(current_10);
  }
  prev_10 = current_10;
  return x;
}

void print_p10(int val) {
  char buffer30 [5];
  sprintf(buffer30, "+%03d", val);
  Serial.println(buffer30);
}

//P11

int current_11, prev_11, delta_11;
int deltaValue_11 = deltaG;

int scaleI3(int input, int mxt, int lmt) {
  int x;
  x = analogRead(input);
  x = map(x, 0, 1023, 999, 0);
  current_11 = x;
  delta_11 = abs(prev_11 - current_11);
  if (delta_11 >= deltaValue_11) {
    print_p11(current_11);
  }
  prev_11 = current_11;
  return x;
}

void print_p11(int val) {
  char buffer31 [5];
  sprintf(buffer31, "=%03d", val);
  Serial.println(buffer31);
}

//P12

int current_12, prev_12, delta_12;
int deltaValue_12 = deltaG;

int scaleI4(int input, int mxt, int lmt) {
  int x;
  x = analogRead(input);
  x = map(x, 0, 1023, 999, 0);
  current_12 = x;
  delta_12 = abs(prev_12 - current_12);
  if (delta_12 >= deltaValue_12) {
    print_p12(current_12);
  }
  prev_12 = current_12;
  return x;
}

void print_p12(int val) {
  char buffer32 [5];
  sprintf(buffer32, ">%03d", val);
  Serial.println(buffer32);
}

void GUI_outs_ins() {
  int p1 = map(k1,0,999,0,40);
  int p2 = map(k2,0,999,0,40);;
  int p3 = map(k3,0,999,0,40);;
  int p4 = map(k4,0,999,0,40);;
  int p5 = map(k5,0,999,0,40);;
  int p6 = map(k6,0,999,0,40);;
  int p7 = map(k7,0,999,0,40);;
  int p8 = map(k8,0,999,0,40);;
  int p9 = map(k11,0,999,0,40);;
  int p10 = map(k12,0,999,0,40);;
  int p11 = map(k13,0,999,0,40);;
  int p12 = map(k14,0,999,0,40);;
  if (b7 == 0) {
    lines_ch(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
  } else {
    lines_ch(current_1 / 25, current_2 / 25, current_3 / 25, current_4 / 25, current_5 / 25, current_6 / 25, current_7 / 25, current_8 / 25, current_9 / 25, current_10 / 25, current_11 / 25, current_12 / 25);
  }
  display.drawRect(0, 81, 64, 45, WHITE);
}
