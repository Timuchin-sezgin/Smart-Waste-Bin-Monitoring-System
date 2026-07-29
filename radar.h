#ifndef RADAR_H
#define RADAR_H

#include <Arduino.h>

extern int moveDistance;
extern int moveEnergy;

extern int staticDistance;
extern int staticEnergy;

extern int detectDistance;

extern int filteredDistance;

extern String radarStatus;

void initRadar();
void readRadar();

#endif