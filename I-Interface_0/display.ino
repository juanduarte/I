//display definitions
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
int inByte = 0;
Adafruit_SSD1306 display(128, 64, &Wire, 4);
int rot_disp1 = 45;
float angle = 0.0;

int squareGUI, squareGUI1, squareGUI2, squareGUI3, bar1GUI, bar2GUI, bar3GUI;

void setup_display() {
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  //display.display();
  display.setRotation(rot_disp1);
  display.invertDisplay(false);
  delay(100);
  Serial.println("display_ready");
  display.clearDisplay();
}

void displayGUI() {
  display.invertDisplay(file_ch);
  int enc = rotaryPosition;
  display.clearDisplay();
  scroll();
  GUI_t();
  touch_disp();
  GUI_buttons();
  GUI_outs_ins();
  display.display();
  delay(10);
  file_ch = false;
}

void lines_ch(int o1, int o2, int o3, int o4,
              int o5, int o6, int o7, int o8,
              int i1, int i2, int i3, int i4) {
  //OUTS
  int t = (millis() % 24000) / 1000;
  o1 = constrain(o1,0,40);
  o2 = constrain(o2,0,40);
  o3 = constrain(o3,0,40);
  o4 = constrain(o4,0,40);
  o5 = constrain(o5,0,40);
  o6 = constrain(o6,0,40);
  o7 = constrain(o7,0,40);
  o8 = constrain(o8,0,40);
  i1 = constrain(i1,0,40);
  i2 = constrain(i2,0,40);
  i3 = constrain(i3,0,40);
  i4 = constrain(i4,0,40);
  
  display.drawLine(3, 124, 3, 124 - o1, WHITE); //100-124
  display.drawLine(7, 124, 7, 124 - o2, WHITE);
  display.drawLine(11, 124, 11, 124 - o3, WHITE);
  display.drawLine(15, 124, 15, 124 - o4, WHITE);
  display.drawLine(19, 124, 19, 124 - o5, WHITE);
  display.drawLine(23, 124, 23, 124 - o6, WHITE);
  display.drawLine(27, 124, 27, 124 - o7, WHITE);
  display.drawLine(31, 124, 31, 124 - o8, WHITE);
  //INS
  display.drawLine(49, 124, 49, 124 - i1, WHITE);
  display.drawLine(53, 124, 53, 124 - i2, WHITE);
  display.drawLine(57, 124, 57, 124 - i3, WHITE);
  display.drawLine(61, 124, 61, 124 - i4, WHITE);
}

void GUI_buttons() {
  //2 ROW
  int xyz = millis() % 1000;
  display.drawCircle(4, 64, 4, WHITE);
  //display.drawCircle(14, 64, 4, WHITE);
  display.drawCircle(24, 64, 4, WHITE);
  if (mode1 == 1 && xyz < 500) {
    display.fillCircle(4, 64, 4, WHITE);
  } else if (mode1 == 2 && xyz % 250 < 125) {
    display.fillCircle(4, 64, 4, WHITE);
  }
  if (mode2 == 1 && xyz < 500) {
    display.fillCircle(24, 64, 4, WHITE);
  } else if (mode2 == 2 && xyz % 250 < 125) {
    display.fillCircle(24, 64, 4, WHITE);
  }
  GUI_numChan();
}

void GUI_numChan() {
  //INPUTS
  int x1 = 45;
  int y1 = 64;
  int x2 = 56;
  int y2 = 73;
  uint16_t C1 = WHITE;
  uint16_t C2 = BLACK;
  if (mode1 == 0) {
    display.fillCircle(x1, y1, 4, C1);
    display.fillCircle(x2, y1, 4, C1);
    display.fillCircle(x1, y2, 4, C1);
    display.fillCircle(x2, y2, 4, C1);
    display.setTextColor(C2);
    textCH(x1 - 2, y1 - 3, bb2);
    textCH(x2 - 2, y1 - 3, bb3);
    textCH(x1 - 2, y2 - 3, bb4);
    textCH(x2 - 2, y2 - 3, bb5);
  } else if (mode1 == 1) {
    display.drawCircle(x1, y1, 4, C1);
    display.drawCircle(x2, y1, 4, C1);
    display.drawCircle(x1, y2, 4, C1);
    display.drawCircle(x2, y2, 4, C1);
    display.setTextColor(C1);
    textCH(x1 - 2, y1 - 3, bb2);
    textCH(x2 - 2, y1 - 3, bb3);
    textCH(x1 - 2, y2 - 3, bb4);
    textCH(x2 - 2, y2 - 3, bb5);
  } else if (mode1 == 2) {
    int norbb2 = (bb2 / 10) % 2;
    int norbb3 = (bb3 / 10) % 2;
    int norbb4 = (bb4 / 10) % 2;
    int norbb5 = (bb5 / 10) % 2;
    if (norbb2 > 0) {
      display.fillCircle(x1, y1, 4, C1);
    } else {
      display.drawCircle(x1, y1, 4, C1);
    }
    if (norbb3 > 0) {
      display.fillCircle(x2, y1, 4, C1);
    } else {
      display.drawCircle(x2, y1, 4, C1);
    }
    if (norbb4 > 0) {
      display.fillCircle(x1, y2, 4, C1);
    } else {
      display.drawCircle(x1, y2, 4, C1);
    }
    if (norbb5 > 0) {
      display.fillCircle(x2, y2, 4, C1);
    } else {
      display.drawCircle(x2, y2, 4, C1);
    }
  }
}

void textCH(int x, int y, int v) {
  display.setCursor(x, y);
  display.println(v + 1);
}

void touch_disp() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 30);
  display.println("SQ");
  display.setCursor(0, 40);
  display.println("BA");
  display.setCursor(0, 50);
  display.println("SL");
}

void GUI_t() {
  float b1 = map(bar1GUI, 4, 96, 0, 2);
  float b2 = map(bar2GUI, 4, 96, 0, 2);
  float b3 = map(bar3GUI, 4, 96, 0, 2);
  
  display.writeFillRect(15, 30, squareGUI / 40, 1, WHITE); //1800 square
  display.writeFillRect(15, 32, squareGUI1 / 40, 1, WHITE);
  display.writeFillRect(15, 34, squareGUI2 / 40, 1, WHITE);
  display.writeFillRect(15, 36, squareGUI3 / 40, 1, WHITE);
  display.writeFillRect(15, 40, b1, 1, WHITE); //3200 bar
  display.writeFillRect(15, 42, b2, 1, WHITE);
  display.writeFillRect(15, 44, b3, 1, WHITE);
  display.writeFillRect(15, 50, curValue / 6, 4, WHITE); //255 slider
}

void scroll() {
  int pos = rotaryPosition % numPatches;
  patchSel = pos;
  int space = pos * (SCREEN_HEIGHT/numPatches);
  display.drawLine(0, 20, 64, 20, WHITE);
  display.drawLine(0, 20,space, 20, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("#:");
  display.setCursor(15, 10);
  display.println(patch_Name[pos]);
}

void disp_test(int val, int sld) {
  int z  = millis()%1000;
  z = z/1000;
  //display.invertDisplay(z);
  display.clearDisplay();
//  for(int i = 0; i < SCREEN_WIDTH; i++){
//    display.drawLine(i,0,SCREEN_WIDTH-i,SCREEN_HEIGHT,WHITE);
//    display.drawLine(0,i,SCREEN_WIDTH,SCREEN_HEIGHT-i,WHITE);
//    display.drawLine(random(i),random(64),random(i),random(64),BLACK);
//  }
//  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(millis()/100);
  display.setCursor(0, 30);
  display.setTextSize(1);
  display.println("loading");
  display.setCursor(0, 60);
  display.setTextSize(4);
  display.println("I");
  display.display();
  
}

void spiro(int val) {
  angle += 0.09;
  //display.setCursor(128 / 2, 64 / 2);
  int radio = 250;
  //int w = 128;
  //int h = 64;
  int w = 128;
  int h = 64;
  float x = (cos(angle) * w);
  float y = (cos(angle) * h);
  float a = (cos(angle * val) * w);
  float b = (sin(angle * val) * h);
  for (int z = 0; z < 25; z++) {
    display.drawCircle(x * z, y, radio, WHITE);
    display.drawCircle(a, b * z, radio, WHITE);
  }
}
