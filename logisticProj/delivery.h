//delivery.h

#ifndef DELIVERY_H
#define DELIVERY_H

#include"city.h"
#include "distance.h"
#include "vehicle.h"

typedef struct
{
    int sourceIndex;
    int destinationIndex;
    double weight;
    int vehicleIndex;
}Delivery;

void handleDeliveryRequest(char cities[][30], int cityCount, int distance[MAX_CITIES][MAX_CITIES],
                           Vehicle vehicles[]);






#endif // DELIVERY_H
