#include<Wire.h>

const int MPU=0x68;  
int AcX,AcY,AcZ,GyX,GyY,GyZ;
double Tmp = 0.0;

void setGyroscope(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0x00); 
  Wire.endTransmission(true);
}
void onGyroscope(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  //Solicita os dados do sensor
  Wire.requestFrom(MPU,14,true);  
  //Armazena o valor dos sensores nas variaveis correspondentes
  AcX=Wire.read()<<8|Wire.read();  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  int tmp=Wire.read()<<8|Wire.read();  //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

if(!isnan(tmp)) {
Tmp = tmp/340.00+36.53;
}

}

String getGyroAc() {
    if(fabs(AcX) > 2000 || fabs(AcY) > 2000) {
        return "Em movimento...";
    } else {
        return "Robo parado";
    }
}

String getGyroGy() {
    if(fabs(GyX) < 300 || fabs(GyY) < 300 || fabs(GyZ) < 300) {
        return "Local nivelado";
    } else {
        return "Robo desnivelado";
    }
}

void onGyroAc() {
    if(fabs(AcX) > 2000 || fabs(AcY) > 2000) {
        onGreen();
    } else {
        onGreenOff();
    }
}

double getGyroTemp() {
    return Tmp;
}

int getGyroAcX() {
    return AcX;
}

int getGyroAcY() {
    return AcY;
}

int getGyroAcZ() {
    return AcZ;
}

int getGyroGyX() {
    return GyX;
}

int getGyroGyY() {
    return GyY;
}

int getGyroGyZ() {
    return GyZ;
}