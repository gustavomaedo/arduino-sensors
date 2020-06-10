int control = 0;
bool startControl = false;
int first = 3;

void onSelect() {
    control = controllerValue();
  if(startControl) {
      switch(control) {
    case 1:
      messageAndBattery();
      break;
    case 2:
      tempAndBright();
      break;
    case 3:
      gyroscope();
      break;
    case 4:
      distance();
      break;
    case 5:
        codeAndLeds();
      break;
    default:
      onDisplay("Robot One", "Display");
  }
  } else {
      if(first > 2) {
          onDisplay("Robot One", "Carregando...");
      } else {
          onDisplay("Bem-vindo ao", "Robot One");
      }
  }

  if(first > 0) {
      first -= 1;
    } else {
        startControl = true;
    }
}

void messageAndBattery() {
    String b = String(62);
    onDisplay("Robot One", "Bateria: " + b + "%");
}

void tempAndBright() {
    double tempG = getGyroTemp();
    double tempD = getTemperature();
    double tempC = tempG;
    if(tempD != 0) {
        tempC = (tempG + tempD) / 2;
    }
    String t = String(tempC);
    String h = String(getHumidity());
    String l = String(getBright());
    onDisplayC("Temp: " + t + "*C", "Hmd: " + h + "%", "Lmn: " + l + "%");
}

void gyroscope() {
    String ac = getGyroAc();
    String gy = getGyroGy();
    onDisplay(ac, gy);
}

void distance() {
    String cm = String(getDistanceCm());
    String in = String(getDistanceIn());
    String obj = getDistanceObj();
    onDisplay(obj, cm + "cm | " + in + "in");
}

void codeAndLeds() {
    String code = String(serialCode());
    String re = "off";
    String gr = "off";
    String bl = "off";
    if(readRed()) {
        re = "on";
    }
    if(readGreen()) {
        gr = "on";
    }
    if(readBlue()) {
        bl = "on";
    }
      onDisplay("Codigo: " + code, "R " + re + " | G " + gr + " | B " + bl);
}
