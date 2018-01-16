#include <Adafruit_NeoPixel.h>

void shiftColor(double color[3], double* goalColor, double shiftSpeed);
void moveColorsDown(double (*colors)[3], int nrOfLights);
void displayStrip(double (*colors)[3], Adafruit_NeoPixel *pixels, int nrOfLights);
