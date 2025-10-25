//delivery.c
#include <stdio.h>
#include "delivery.h"

#define FUEL_PRICE 310.00  //LKR per litre

void handleDeliveryRequest(char cities[][30], int cityCount, int distance[MAX_CITIES][MAX_CITIES],
                           Vehicle vehicles[], Delivery deliveries[], int *deliveryCount)
{
    if(*deliveryCount >= MAX_DELIVERIES)
    {
        printf("Delivery record limit (%d) reached!\n", MAX_DELIVERIES);
        return;
    }


    Delivery d;
    //int valide = 1;

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
    d.distance = distance[d.sourceIndex - 1][d.destinationIndex - 1];

    if(d.distance <= 0)
    {
        printf("Error: Distance between %s and %s is not set yet.\n",
               cities[d.sourceIndex - 1], cities[d.destinationIndex - 1]);
        return;
    }

    //weight
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

    Vehicle v = vehicles[d.vehicleIndex - 1];

    if (d.weight > v.capacity)
    {
        printf("Error: Weight %.2f kg exceeds %s capacity (%d kg)\n",
               d.weight, v.type, v.capacity);
        return;
    }

    //step 05: cost, time, fuel calculations e

    //a.delivery cost
    d.deliveryCost = d.distance * selected.ratePerKm * (1 + d.weight*(1/10000));

    //b.estimated delivery time(hours)
    d.timeHours =  d.distance / v.speed;

    //c.fuel consumption
    d.fuelUsed = d.distance / v.efficiency;

    //d. Fuel Cost:
    d.fuelCost = d.fuelUsed * FUEL_PRICE;

    //e.Total Operational Cost
    d.totalCost = d.deliveryCost + d.fuelCost;

    //f.profit(25% of base delivery cost)
    d.profit = d.deliveryCost * 0.25;

    //g.final customer charge
    d.cutomerCharge = d.totalCost + d.profit;

    //storing delivery record
    deliveries[*deliveryCount] = d;
    (*deliveryCount)++


    //output
    printf("\n--- DELIVERY SUMMARY ---\n");
    printf("From            : %s\n", cities[d.sourceIndex - 1]);
    printf("To              : %s\n", cities[d.destinationIndex - 1]);
    printf("Vehile          : %s\n", v.type);
    printf("Distance        : %.2f km\n", d.distance);
    //printf("Vehicle         : %s\n", selected.type);
    printf("Weight          : %.2f kg\n", d.weight);
    printf("--------------------------\n");
    printf("Delivery Cost   : LKR %.2f\n", d.deliveryCost);
    printf("Fuel Used       : %.2f liters\n", d.fuelUsed);
    printf("Fuel Cost       : LKR %.2f\n", d.fuelCost);
    printf("OPerational Cost: LKR %.2f\n", d.totalCost);
    printf("Estimated Time  : %.2f hours\n", d.timeHours);
    printf("Profit (25%%)   : LKR %.2f\n", d.profit);
    printf("-------------------------------------------------\n");
    printf("Final Customer Charge   : LKR %.2f\n", d.cutomerCharge);
    printf("=====================================================\n");


    void viewAllDeliveries(char cities[][30], Delivery deliveries[], int deliveryCount)
{
    if (deliveryCount == 0)
    {
        printf("\nNo deliveries recorded yet.\n");
        return;
    }

    printf("\n================= DELIVERY RECORDS =================\n");
    printf("%-3s %-12s %-12s %-8s %-10s %-10s\n",
           "No", "Source", "Destination", "Veh", "Dist(km)", "Charge");

    for (int i = 0; i < deliveryCount; i++)
    {
        printf("%-3d %-12s %-12s %-8d %-10.2f %-10.2f\n",
               i + 1,
               cities[deliveries[i].sourceIndex - 1],
               cities[deliveries[i].destinationIndex - 1],
               deliveries[i].vehicleIndex,
               deliveries[i].distance,
               deliveries[i].customerCharge);
    }

    printf("=====================================================\n");


}
