#include <Ultrasonic.h>

#define pin_trigger 2
#define pin_echo 3
 
Ultrasonic ultrasonic(pin_trigger, pin_echo);

float cmMsec = 0, inMsec = 0;
 
void setDistance()
{
  long microsec = ultrasonic.timing();
  float cm = ultrasonic.convert(microsec, Ultrasonic::CM);
  float in = ultrasonic.convert(microsec, Ultrasonic::IN);

    if(!isnan(cm)) {
        cmMsec = cm;
    }

    if(!isnan(in)) {
        inMsec = in;
    }
}

float getDistanceCm() {
    return cmMsec;
}

float getDistanceIn() {
    return inMsec;
}

void setDistanceObj() {
    if(cmMsec < 15) {
        onRed();
    } else if(cmMsec < 40) {
        onRedOn();
    } else if(cmMsec < 240) {
        onRedOff();
    } else {
        onRedOff();
    }
}

String getDistanceObj() {
    if(cmMsec < 15) {
        return "Objeto perto";
    } else if(cmMsec < 40) {
        return "Objeto proximo";
    } else if(cmMsec < 240) {
        return "Objeto longe";
    } else {
        return "Nenhum objeto";
    }
}