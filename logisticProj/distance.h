//distance.h
#ifndef DISTANCE_H
#define DISTANCE_H

#include "city.h"

void initializeDistance(int distance[MAX_CITIES][MAX_CITIES], int cityCount);
void inputOrEditDistance(int distance[MAX_CITIES][MAX_CITIES], char citiies[][30], int cityCount);
void displayDistanceTable(int distance[MAX_CITIES][MAX_CITIES], char citiies[][30], int cityCount);

#endif
