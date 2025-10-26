//delivery.h

#ifndef DELIVERY_H
#define DELIVERY_H

#include"city.h"
#include "distance.h"
#include "vehicle.h"

#define MAX_DELIVERIES 50

typedef struct
{
    int sourceIndex;    // Source city index
    int destinationIndex;   // Destination city index
    double weight;      // Cargo weight (kg)
    int vehicleIndex;   // Selected vehicle
    double distance;    // Total distance (km)
    double deliveryCost;     // Base delivery cost
    double timeHours;   // Estimated time
    double fuelUsed;     // Fuel consumption (liters)
    double fuelCost;    // Fuel cost (LKR)
    double totalCost;   // Operational cost
    double profit;      // Profit margin
    double customerCharge;  // Final customer charge

}Delivery;

void handleDeliveryRequest(char cities[][30], int cityCount,
                           int distance[MAX_CITIES][MAX_CITIES],
                           Vehicle vehicles[],
                           Delivery deliveries[], int *deliveryCount);

void viewAllDeliveries(char cities[][30], Delivery deliveries[], int deliveryCount);

void saveDeliveriesToFile(Delivery deliveries[], int deliveryCount, char cities[][30]);
int loadDeliveriesFromFile(Delivery deliveries[], int *deliveryCount, char cities[][30]);


#endif // DELIVERY_H
