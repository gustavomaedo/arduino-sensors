char code = '0';
bool codeGo = true;
bool initSerial = false;

void onSerial(int n) {
  Serial.begin(n);
}

char serialCode() {
    return code;
}

void serialEvent() {
  if (Serial.available()) {
      char icode = Serial.read();
      if(isAlphaNumeric(icode)) {
        codeGo = true;
        initSerial = true;
        code = icode;
      }
    }
}

void onSerialSelect() {
  if(codeGo) {
      switch(code) {
    case 't':
      onSendTHL();
      break;
    case 'd':
      onSendDistance();
      break;
    case 'g':
      onSendGyroscope();
      break;

    case 'R':
      onRed();
      break;
    case 'G':
      onGreen();
      break;
    case 'B':
      onBlue();
      break;
    default:
    if(!initSerial) {
        onBlueOn();
    }
  }
      codeGo = false;
  }
}
