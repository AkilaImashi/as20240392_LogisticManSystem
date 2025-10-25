//vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#define VEHICLE_COUNT 3

typedef struct {
    char type[20];
    int capacity;
    double ratePerKm;
    double speed;
    double efficiency;


}Vehicle;

void initializeVehicles(Vehicle vehicles[]);
void displayVehicles(Vehicle vehicles[]);
int chooseVehicle(Vehicle vehicles[]);


#endif // VEHICLE_H
