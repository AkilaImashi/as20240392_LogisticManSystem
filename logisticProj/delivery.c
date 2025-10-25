//delivery.c
#include <stdio.h>
#include "delivery.h"

void handleDeliveryRequest(char cities[][30], int cityCount, int distance[MAX_CITIES][MAX_CITIES],
                           Vehicle vehicles[])
{
    Delivery d;
    int valide = 1;

    printf("\n======Delivery Request=====\n");

    //display cities
    for(int i = 0; i < cityCount;  i++)
        printf("%2d. %s\n", i + 1, cities[i]);

    printf("\nEnter source city number: ");
    scanf("%d", &d.sourceIndex);


    printf("Enter destination city number: ");
    scanf("%d", &d.destinationIndex);

    //validate city number
    if(d.sourceIndex < 1 || d.sourceIndex > cityCount ||
            d.destinationIndex < 1 || d.destinationIndex > cityCount)
    {
        printf("Invalid city numbers!\n");
        return;
    }

    //validate source != destination
    if(d.sourceIndex == d.destinationIndex)
    {
        printf("Error! source and destinaion cannot be same \n");
        return;
    }

    //check distance availability
    int dist= distance[d.sourceIndex - 1][d.destinationIndex - 1];

    if(dist <= 0)
    {
        printf("Error: Distance between %s and %s is not set yet.\n",
               cities[d.sourceIndex - 1], cities[d.destinationIndex - 1]);
        return;
    }

    printf("Enter weight of goods(kg): ");
    scanf("%lf", &d.weight);

    if(d.weight <=0)
    {
        printf("invalid weight!\n");
        return;
    }

    //choose vehicle
    printf("\nSelect vehicle type:\n");
    for(int i = 0; i < VEHICLE_COUNT; i++)
    {
        printf("%d. %s(Capacity : %d kg)\n", i + 1, vehicles[i].type,
               vehicles[i].capacity);
    }
    printf("Enter choice: ");
    scanf("%d", &d.vehicleIndex);

    if(d.vehicleIndex < 1 || d.vehicleIndex > VEHICLE_COUNT)
    {
        printf("Invalid vehicle selection\n");
        return;
    }

    Vehicle selected = vehicles[d.vehicleIndex - 1];

    if (d.weight > selected.capacity)
    {
        printf("Error: Weight %.2f kg exceeds %s capacity (%d kg)\n",
               d.weight, selected.type, selected.capacity);
        return;
    }

    printf("\n--- DELIVERY SUMMARY ---\n");
    printf("From : %s\n", cities[d.sourceIndex - 1]);
    printf("To   : %s\n", cities[d.destinationIndex - 1]);
    printf("Distance   : %d km\n", dist);
    printf("Vehicle    : %s\n", selected.type);
    printf("Weight     : %.2f kg\n", d.weight);
    printf("--------------------------\n");
    printf("Validation successful! (Ready for cost calculation )\n");



}
