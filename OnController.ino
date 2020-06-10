const int controller = 7;

int controllerValue() {
    int c = analogRead(controller);
    if (c < 203) {
        c = 1;
    } else if (c < 407) {
        c = 2;
    } else if (c < 611) {
        c = 3;
    } else if (c < 815) {
        c = 4;
    } else if (c < 1025) {
        c = 5;
    }
    return c;
}