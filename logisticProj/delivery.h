//delivery.h

#ifndef DELIVERY_H
#define DELIVERY_H

#include"city.h"
#include "distance.h"
#include "vehicle.h"

#define MAX_DELIVERIES 50

typedef struct
{
    int sourceIndex;
    int destinationIndex;
    double weight;      //kg
    int vehicleIndex;
    double distance;    //in km
    double deliveryCost;
    double timeHours;
    double fuelUsed;
    double fuelCost;
    double totalCost;
    double profit;
    double cutomerCharge;

}Delivery;

void handleDeliveryRequest(char cities[][30], int cityCount, int distance[MAX_CITIES][MAX_CITIES],
                           Vehicle vehicles[]);

void viewAllDeliveries(char cities[][30], Delivery deliveries[], int deliveryCount);




#endif // DELIVERY_H
