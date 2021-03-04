#include <SPI.h>
#include <Wire.h>
#include <Encoder.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EasyButton.h>
#include <Trill.h>

//Encoder definiitons
Encoder myEnc(3, 2); //20,21
int oldPosition  = -999;
unsigned long rotaryPosition; //encoder1
uint8_t prevValue; //touchslider
uint8_t curValue;
int b1, b2, b3, b4, b5, b6, b7, b8; //buttons
int k1, k2, k3, k4, k5, k6, k7, k8; //potentiometers out
int k11, k12, k13, k14; //potentiometers in

int numPatches = 3;
String patch_Name [] {"Bypass", "Manual","Presets"}; 

void establishContact() {
  while (Serial.available() <= 0) {
    disp_test(666, 666);
  }
}

void setup() {
  Serial.begin(4800);
  setup_display();
  delay(10);
  setup_trill();
  delay(10);
  setup_touch();
  delay(10);
  set_pots();
  delay(10);
  establishContact();//wait for pd to start
  delay(10);
  setupButtons();
  delay(10); 
}

void loop() {
  encoder_m();
  buttons();
  touch_p();
  trill();
  displayGUI();
  potentiometers(); 
  delay(1);
}
