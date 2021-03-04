Trill ts0; //square 0-1800
Trill ts1; //bar2 0-3200
Trill ts2; //bar1

boolean ta0 = false; // touchActive
boolean ta1 = false; //
boolean ta2 = false; //

int noiseRef = 50; //0-255

void setup_trill() {
  ts0.setup(Trill::TRILL_SQUARE, 40);
  ts1.setup(Trill::TRILL_BAR, 32);
  ts2.setup(Trill::TRILL_BAR, 34);
  delay(150);
  ts0.setScanSettings(0, 16);
  ts1.setScanSettings(0, 16);
  ts2.setScanSettings(0, 16);
  ts0.setNoiseThreshold(noiseRef);
  ts1.setNoiseThreshold(noiseRef);
  ts2.setNoiseThreshold(noiseRef);
  ts0.setPrescaler(4);
  ts1.setPrescaler(4);
  ts2.setPrescaler(4);
  delay(150);
  ts0.setMode(Trill::CENTROID);
  trill();
  delay(100);
  trill();
  Serial.println("Trill ready");
  
}

void trill() {
  ts0.read(); //square
  ts1.read(); //bar1
  int x = ts0.getNumTouches();
  int y = ts1.getNumTouches();
  int z = ts2.getNumTouches();
  sensor1(x, ta0);
  sensor2(y, ta1);
  touchSQ = x;
  touchBR = y;
}

void sensor1(int numt, int sw) {
  if (numt > 0) {
    for (int i = 0; i < numt; i++) {
      squareGUI = ts0.touchLocation(0);
      squareGUI1 = ts0.touchLocation(1);
      squareGUI2 = ts0.touchLocation(2);
      squareGUI3 = ts0.touchLocation(3);
      char buffer00 [10];
      char buffer03 [10];
      char buffer06 [10];
      sprintf(buffer00, "s%03d", ts0.touchLocation(i)/18); //115
      sprintf(buffer03, "~%03d", ts0.touchHorizontalSize(i)); //126
      sprintf(buffer06, "/%03d", ts0.getNumTouches()); // 47
      Serial.println(buffer00);
      Serial.println("");
      Serial.println(buffer03);
      Serial.println("");
      Serial.println(buffer06);
      Serial.println("");
    }
    //Serial.println("");
    sw = true;
    
  }
  else if (ta0) {
    // Print a single line when touch goes off
    //Serial.println("off");
    sw = false;
  }
  delay(10);
}

void sensor2(int numt, int sw) {
  if (numt > 0) {
    for (int i = 0; i < numt; i++) {
      bar1GUI = ts1.touchLocation(0);
      bar2GUI = ts1.touchLocation(1);
      bar3GUI = ts1.touchLocation(2);
      char buffer01 [10];
      char buffer04 [10];
      char buffer07 [10];
      sprintf(buffer01, "r%03d", ts1.touchLocation(i)/32); //114
      sprintf(buffer04, "{%03d", ts1.touchHorizontalSize(i)); //123
      sprintf(buffer07, "[%03d", ts1.getNumTouches()); //91
      Serial.println(buffer01);
      Serial.println("");
      Serial.println(buffer04);
      Serial.println("");
      Serial.println(buffer07);
      Serial.println("");
    }
    //Serial.println("");
    sw = true;
  }
  else if (ta0) {
    // Print a single line when touch goes off
    //Serial.println("off");
    sw = false;
  }
  delay(10);
}

void sensor3(int numt, int sw) {
  if (numt > 0) {
    for (int i = 0; i < numt; i++) {
      bar2GUI = ts2.touchLocation(i);
      char buffer02 [10];
      char buffer05 [10];
      char buffer08 [10];
      sprintf(buffer02, "t%03d", ts2.touchLocation(i)/32); //116
      sprintf(buffer05, "}%03d", ts2.touchHorizontalSize(i)); //125
      sprintf(buffer08, "]%03d", ts2.getNumTouches()); //92
      Serial.println(buffer02);
      Serial.println("");
      Serial.println(buffer05);
      Serial.println("");
      Serial.println(buffer08);
      Serial.println("");
    }
    //Serial.println("");
    sw = true;
  }
  else if (ta0) {
    // Print a single line when touch goes off
    //Serial.println("off");
    sw = false;
  }
  delay(10);
}
