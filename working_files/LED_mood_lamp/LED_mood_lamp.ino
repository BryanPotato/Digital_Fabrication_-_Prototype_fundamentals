
int redPin = 11;
int greenPin = 9;
int bluePin = 10;

const int switchPin = 12;

int r = 0;
int g = 0;
int b = 0;


int switchState = 0;
 
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  
  pinMode(switchPin, INPUT);
}
 
void loop()
{
  switchState = digitalRead(switchPin);

  if (switchState == HIGH ) //if it is,the state is HIGH

  {
  setColor(255, 0, 0);  // red
  delay(10);
  setColor(0, 255, 0);  // green
  delay(10);
  setColor(0, 0, 255);  // blue
  delay(10);
  //setColor(255, 255, 0);  // yellow
  //delay(10); 
  setColor(80, 0, 80);  // purple
  delay(10);
  setColor(0, 255, 255);  // aqua
  delay(10);
  }

  else
  {
    setColor(0,0,0);
  }
  
}
 
void setColor(int red, int green, int blue)
{
  while ( r != red || g != green || b != blue ) {
    if ( r < red ) r += 1;
    if ( r > red ) r -= 1;

    if ( g < green ) g += 1;
    if ( g > green ) g -= 1;

    if ( b < blue ) b += 1;
    if ( b > blue ) b -= 1;

    _setColor();
    delay(10);
  }
}

void _setColor() {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b); 
}
