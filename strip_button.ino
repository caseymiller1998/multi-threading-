#include <Adafruit_NeoPixel.h>

int buttonPin = 2;    // momentary push button on pin 0
int oldButtonVal = 0;
#define pixels 41  
#define PIN 3    // Parameter 1 = number of pixels in strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixels, PIN, NEO_GRB + NEO_KHZ800);

int nPatterns = 2;
int lightPattern = 1;
uint16_t currentPixel = 0;// what pixel are we operating on
uint16_t led=0;

unsigned long previousmillis = 0;
unsigned long time = 35;
// the setup routine runs once when you press reset:
void setup() {
  strip.begin();
  strip.show();                // initialize all pixels to 'off'    
  currentPixel=0;                           // initialize the BUTTON pin as an input
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);  // button pin is HIGH, so it drops to 0 if pressed
}


void pattern1() {

  strip.setPixelColor(currentPixel,0,255,0);
  strip.show();
  currentPixel++;
  if(currentPixel == pixels){
    currentPixel = 0;

  }
  strip.setPixelColor(currentPixel,0,0,225);
  strip.show();
  currentPixel++;
  if(currentPixel == pixels){
    currentPixel = 0;
  }
  led=0;
}


// Pattern 2 - Red light, all LEDs in the strip are red
void pattern2() {
  strip.setPixelColor(led,0,0,255);
  strip.show();
  led++;
  if(led == pixels){
    led = 0;
    for (int i = 0; i < pixels; i++)  // clear the strip
    {
      strip.setPixelColor(i,0,255,0);
    }
  }
  currentPixel=0;
}



// the loop routine runs over and over again forever;
void loop() {
  // read that state of the pushbutton value;
  int buttonVal = digitalRead(buttonPin);
  if (buttonVal == LOW && oldButtonVal == HIGH) {// button has just been pressed
    lightPattern = lightPattern + 1;
  }
  if (lightPattern > nPatterns) lightPattern = 1;
  oldButtonVal = buttonVal;

  switch(lightPattern) {
  case 1:
    if ((unsigned long)(millis() - previousmillis) >= time) {
      previousmillis = millis();
      pattern1();
      break;
  case 2:
      if ((unsigned long)(millis() - previousmillis) >= time) {
        previousmillis = millis();
        pattern2();
        break;

      }
    }
  }
}






