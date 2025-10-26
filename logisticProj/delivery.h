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
    double customerCharge;

}Delivery;

void handleDeliveryRequest(char cities[][30], int cityCount,
                           int distance[MAX_CITIES][MAX_CITIES],
                           Vehicle vehicles[],
                           Delivery deliveries[], int *deliveryCount);

void viewAllDeliveries(char cities[][30], Delivery deliveries[], int deliveryCount);

void saveDeliveriesToFile(Delivery deliveries[], int deliveryCount, char cities[][30]);
int loadDeliveriesFromFile(Delivery deliveries[], int *deliveryCount, char cities[][30]);


#endif // DELIVERY_H
