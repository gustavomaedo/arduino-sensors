void onSendTHL() {
    open();
    key("t_dht");
    value(String(getTemperature()));
    key("t_gy");
    value(String(getGyroTemp()));
    key("h_dht");
    value(String(getHumidity()));
    key("ldr");
    valueL(String(getBright()));
    close();

}

void onSendDistance() {
    open();
    key("d_cm");
    value(String(getDistanceCm()));
    key("d_in");
    valueL(String(getDistanceIn()));
    close();
}

void onSendGyroscope() {
  open();
    key("ax");
    value(String(getGyroAcX()));
    key("ay");
    value(String(getGyroAcY()));
    key("az");
    value(String(getGyroAcZ()));
    key("gx");
    value(String(getGyroGyX()));
    key("gy");
    value(String(getGyroGyY()));
    key("gz");
    valueL(String(getGyroGyZ()));
    close();
}

void open() {
    Serial.print("{");
}

void close() {
    Serial.print("}");
}

void key(String key) {
    Serial.print('"') +
    Serial.print(key) +
    Serial.print("\":");
}

void value(String value) {
    Serial.print(value);
    Serial.print(",");
}

void valueL(String value) {
    Serial.print(value);
}