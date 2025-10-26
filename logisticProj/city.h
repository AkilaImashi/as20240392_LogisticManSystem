//city.h
#ifndef CITY_H
#define CITY_H

#define MAX_CITIES 30

void getCities(char cities[][30], int *cityCount);
void displayCities(char cities[][30], int cityCount);
void renameCity(char cities[][30], int cityCount);
void addCity(char cities[][30], int *cityCount, int distance[MAX_CITIES][MAX_CITIES]);
void removeCity(char cities[][30], int *cityCount, int distance[MAX_CITIES][MAX_CITIES]);
void cityManagement(char cities[][30], int *cityCount, int distance[MAX_CITIES][MAX_CITIES]);


#endif


