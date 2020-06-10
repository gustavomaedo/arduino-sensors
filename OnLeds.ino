const int red = 11;
const int green = 10;
const int blue = 9;

void setPins() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

bool readRed() {
    if(digitalRead(red) == HIGH) {
        return true;
    } else {
        return false;
    }
}

bool readGreen() {
    if(digitalRead(green) == HIGH) {
        return true;
    } else {
        return false;
    }
}

bool readBlue() {
    if(digitalRead(blue) == HIGH) {
        return true;
    } else {
        return false;
    }
}

void onRedOff() {
  digitalWrite(red, LOW);
}

void onGreenOff() {
  digitalWrite(green, LOW);
}

void onBlueOff() {
  digitalWrite(blue, LOW);
}

void onRedOn() {
    digitalWrite(red, HIGH);
}

void onGreenOn() {
    digitalWrite(green, HIGH);
}

void onBlueOn() {
    digitalWrite(blue, HIGH);
}

void allOn() {
  onRedOn();
  onGreenOn();
  onBlueOn();
}

void allOff() {
  onRedOff();
  onGreenOff();
  onBlueOff();
}

void onRed() {
  if(readRed()) {
      onRedOff();
  } else {
      onRedOn();
  }
}

void onGreen() {
  if(readGreen()) {
      onGreenOff();
  } else {
      onGreenOn();
  }
}

void onBlue() {
  if(readBlue()) {
      onBlueOff();
  } else {
      onBlueOn();
  }
}
