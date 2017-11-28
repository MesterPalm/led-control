#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      30

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 50; 
int red, green, blue;
int cd[NUMPIXELS][3];

void setup() {
  pixels.begin(); 
  randomSeed(analogRead(0));
  for (int i = 0; i < NUMPIXELS; i++){
    cd[i][0] = 0;
    cd[i][1] = 0;
    cd[i][2] = 0;
  }
}

void loop() {
  red = random(256);
  green = random(256);
  blue = random(256);  
   
  cd[0][0] = red;
  cd[0][1] = green;
  cd[0][2] = blue;
  
  pixels.setPixelColor(0, pixels.Color(cd[0][0],cd[0][1],cd[0][2])); 
    
  for (int i = NUMPIXELS; i > 0; i--){
    cd[i][0] = cd[i-1][0];
    cd[i][1] = cd[i-1][1];
    cd[i][2] = cd[i-1][2];
    pixels.setPixelColor(i, pixels.Color(cd[i][0],cd[i][1],cd[i][2]));   
  }
    
   
  pixels.show(); 
  delay(delayval);
}
