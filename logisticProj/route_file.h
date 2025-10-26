// route_file.h
#ifndef ROUTE_FILE_H
#define ROUTE_FILE_H

#include "city.h"
#include "distance.h"

// Save cities and distance matrix to routes.txt
void saveRoutesToFile(char cities[][30], int cityCount,
                      int distance[MAX_CITIES][MAX_CITIES]);

// Load cities and distance matrix from routes.txt
int loadRoutesFromFile(char cities[][30], int *cityCount,
                       int distance[MAX_CITIES][MAX_CITIES]);

#endif // ROUTE_FILE_H
