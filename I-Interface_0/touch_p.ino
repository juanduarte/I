//TouchPotentiometer
int i2cAddr = 8;

void setup_touch() {
  Wire.begin();
  // Demonstrate access to Touch Potentiometer registers
  WriteTpReg(1, 128); // set to 50% by writing to register 1
  curValue = ReadTpReg(1); // read back value just set
  // Set Arduino LED PWM to match
  //analogWrite(13, curValue);
  prevValue = 2000;
  touch_p();

} 

void touch_p() {
  delay(10);  // Read ~20 times/second
  // Demonstrate direct access to Touch Potentiometer value
  curValue = ReadTpValue(); // faster I2C access than register read
  if (curValue != prevValue) {
    char buffer77 [5];
    sprintf(buffer77, "T%03d", curValue);
    Serial.println(buffer77);
    prevValue = curValue;
  }
}

// Write a Touch Potentiometer register
void WriteTpReg(uint8_t addr, uint8_t data) {
  Wire.beginTransmission(i2cAddr + 1);
  Wire.write('W');
  Wire.write(addr);
  Wire.write(data);
  Wire.endTransmission();
}

// Get the Touch Potentiometer value
uint8_t ReadTpValue() {
  Wire.requestFrom(i2cAddr, 1);
  if (Wire.available()) {
    return Wire.read();
  } else {
    return 0;
  }
}

// Read a Touch Potentiometer register
uint8_t ReadTpReg(uint8_t addr) {
  Wire.beginTransmission(i2cAddr + 1);
  Wire.write('R');
  Wire.write(addr);
  Wire.endTransmission();
  Wire.requestFrom(i2cAddr + 1, 1);
  if (Wire.available()) {
    return Wire.read();
  } else {
    return 0;
  }
}
