const int brightPin = 0;             
double bright = 0;                      
 
 void setBright() {
int b = analogRead(brightPin);
  if(!isnan(b)) {
      bright = 100 - (b / 10.24);
  }
}
 
double getBright() {
  return bright;          
}