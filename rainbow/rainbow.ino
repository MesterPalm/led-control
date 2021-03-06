#include <Adafruit_NeoPixel.h>
#include "color_control.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      24

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 30; 
double red, green, blue;
double color[3], goalColor[3];
double cd[NUMPIXELS][3];

void setup() {
  pixels.begin(); 
  randomSeed(analogRead(0));

  pixels.setBrightness(50);
  
  
  for (int i = 0; i < NUMPIXELS; i++){
    cd[i][0] = 1;
    cd[i][1] = 1;
    cd[i][2] = 1;
  }

  color[0] = 1;
  color[1] = 1;
  color[2] = 1;

  goalColor[0] = 1;
  goalColor[1] = 1;
  goalColor[2] = 1;
}

void loop() {
  if(goalColor[0] == cd[0][0]){
    goalColor[0] = 255*random(2);
    goalColor[1] = 255*random(2);
    if(goalColor[0] == goalColor[1]){
      if(goalColor[0] == 255){
        goalColor[2] = 0;
      }
      else{
        goalColor[2] = 255;
      }
    } 
    else{
      goalColor[2] = 255*random(2);
    }
  }

  shiftColor(color, goalColor, 30);

  cd[0][0] = color[0];
  cd[0][1] = color[1];
  cd[0][2] = color[2];
  moveColorsDown(cd, NUMPIXELS);
  displayStrip(cd, &pixels, NUMPIXELS);   
   
  pixels.show(); 
  delay(delayval);
}

