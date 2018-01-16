#include <Adafruit_NeoPixel.h>
#include "color_control.h"
#include <stdlib.h> 

void shiftColor(double color[3], double* goalColor, double shiftSpeed){
  double shift, totalColor, colorDelta, newColorDelta;
  
  totalColor = abs(color[0] - goalColor[0]) + abs(color[1] - goalColor[1]) + abs(color[2] - goalColor[2]);
  
  for(int i = 0; i < 3; i++){
    colorDelta = goalColor[i] - color[i];
    shift = colorDelta/totalColor;
    
    if(colorDelta != 0){
      color[i] += shift*shiftSpeed; 
    }
    
    newColorDelta = goalColor[i] - color[i];
    
    if((newColorDelta > 0 && colorDelta < 0) ||
       (newColorDelta < 0 && colorDelta > 0)){
      color[i] = goalColor[i];
    }
  }
}

void moveColorsDown(double (*colors)[3], int nrOfLights){
    for (int i = nrOfLights-1; i > 0; i--){
    colors[i][0] = colors[i-1][0];
    colors[i][1] = colors[i-1][1];
    colors[i][2] = colors[i-1][2];
  }
}

void displayStrip(double (*colors)[3], Adafruit_NeoPixel *pixels, int nrOfLights){
  for (int i = 0; i < nrOfLights; i++){
    pixels->setPixelColor(i, pixels->Color(colors[i][0],colors[i][1],colors[i][2]));   
  }
}

