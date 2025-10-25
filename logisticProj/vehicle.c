//vehicle.c

#include <stdio.h>
#include <string.h>
#include "vehicle.h"

void initializeVehicles(Vehicle vehicles[])
{
    strcpy(vehicles[0].type,"Van");
    vehicles[0].capacity = 1000;
    vehicles[0].ratePerKm = 30.0;
    vehicles[0].speed = 60.0;
    vehicles[0].efficiency = 12.0;

    strcpy(vehicles[1].type,"Truck");
    vehicles[1].capacity = 5000;
    vehicles[1].ratePerKm = 40.0;
    vehicles[1].speed = 50.0;
    vehicles[1].efficiency = 6.0;

    strcpy(vehicles[2].type,"Lorry");
    vehicles[2].capacity = 10000;
    vehicles[2].ratePerKm = 80.0;
    vehicles[2].speed = 45.0;
    vehicles[2].efficiency = 4.0;
}

void displayVehicles(Vehicle vehicles[])
{
    printf("------Vehicle List-----\n");
    printf("%-10s %-12s %-12s %-12s %-12s\n",
           "Type", "Capacity(kg)", "Rate/km(LKR)", "Speed(km/h)", "Efficiency(km/l)");

    for(int i = 0; i < VEHICLE_COUNT; i++)
    {
        printf("%-10s %-12d %-12.2f %-12.2f %-12.2f\n",
               vehicles[i].type,
               vehicles[i].capacity,
               vehicles[i].ratePerKm,
               vehicles[i].speed,
               vehicles[i].efficiency);
    }
    printf("=====================================================\n");

}

int chooseVehicle(Vehicle vehicles[])
{
    int choice;
    displayVehicles(vehicles);

    printf("\nSelect a vehicle type(1 = Van, 2 = Truck, 3 = Lorry): ");
    scanf("%d", &choice);

    if(choice < 1 || choice > VEHICLE_COUNT)
    {
        printf("Invalid choice! Defaulting to Van.\n");
        choice = 1;
    }

    printf("You selected: %s\n", vehicles[choice - 1].type);
    return choice - 1;


}





