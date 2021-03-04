int encoder_m() {
  rotaryPosition = myEnc.read();
  if (rotaryPosition != oldPosition) {
    oldPosition = rotaryPosition;
  }
  rotaryPosition = constrain(rotaryPosition, 0, 720);
  rotaryPosition = rotaryPosition/4;
  return rotaryPosition;
}
