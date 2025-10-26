// route.h
#ifndef ROUTE_H
#define ROUTE_H

#include "city.h"
#include "distance.h"

#define INF 999999

int findLeastDistance(int distance[MAX_CITIES][MAX_CITIES], int cityCount,
                      int src, int dest, int path[], int *pathLen);


void displayRoute(char cities[][30], int path[], int pathLen, int minDist);

#endif

