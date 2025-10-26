//vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#define VEHICLE_COUNT 3

typedef struct {
    char type[20]; //vehicle type name
    int capacity;   //maximum load capacity
    double ratePerKm;     //cost per kilometer(LKR)
    double speed;   //Average speed(km/h)
    double efficiency;  //fuel efficiency(km/l)


}Vehicle;

void initializeVehicles(Vehicle vehicles[]);
void displayVehicles(Vehicle vehicles[]);
int chooseVehicle(Vehicle vehicles[]);


#endif // VEHICLE_H
