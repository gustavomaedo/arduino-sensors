void setup() {
// put your setup code here, to run once:
    onSerial(9600);
    setDisplay();
    setPins();
    setDht();
    setGyroscope();
}

void loop() {
// put your main code here, to run repeatedly:
    onGyroscope();
    onGyroAc();
    setTempAndHumi();
    setBright();
    setDistance();
    setDistanceObj();
    serialEvent();
    onSerialSelect();
    onSelect();
}
