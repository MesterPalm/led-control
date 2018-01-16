#include "color_control.h"
#include <stdlib.h> 

void shiftColor(double* color, double* goalColor, double shiftSpeed){
  double redShift, greenShift, blueShift, totalColor;
  
  totalColor = abs(color[0] - goalColor[0]) + abs(color[1] - goalColor[1]) + abs(color[2] - goalColor[2]);

  redShift = (color[0] - goalColor[0])/ totalColor;
  greenShift = (color[1] - goalColor[1])/ totalColor;
  blueShift = (color[2] - goalColor[2])/ totalColor;


  
  //if ((redShift*shiftSpeed > 0 && color[0] + redShift*shiftSpeed < goalColor[0]) || (redShift*shiftSpeed < 0 && color[0] + redShift*shiftSpeed > goalColor[0]))
    color[0] = color[0] + (redShift*shiftSpeed);
    color[1] = color[1] + (greenShift*shiftSpeed);
    color[2] = color[2] + (blueShift*shiftSpeed);
  //}
  /*else{
    color[0] = goalColor[0];
    color[1] = goalColor[1];
    color[2] = goalColor[2];
  }*/
  
}
