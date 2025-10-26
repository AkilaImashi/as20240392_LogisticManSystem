//main.c
#include <stdio.h>
#include <string.h>
#include "city.h"
#include "distance.h"
#include "vehicle.h"
#include "delivery.h"
#include "route_file.h"

int main()
{
    char citiesArr[MAX_CITIES][30];
    int cityCount = 0;
    int distance[MAX_CITIES][MAX_CITIES];
    Vehicle vehicles[VEHICLE_COUNT];
    Delivery deliveries[MAX_DELIVERIES];
    int deliveryCount = 0;

    initializeVehicles(vehicles);

    // Initialize distance matrix
    initializeDistance(distance, MAX_CITIES);


    initializeDistance(distance, cityCount);
    initializeVehicles(vehicles);

    //load routes from file
    printf("\n=== Loading saved data ===\n");
    int routesLoaded = loadRoutesFromFile(citiesArr, &cityCount, distance);

    if (!routesLoaded)
    {
        getCities(citiesArr, &cityCount);
        initializeDistance(distance, cityCount);
    }

    // Load delivery history
    loadDeliveriesFromFile(deliveries, &deliveryCount, citiesArr);
    printf("=========================\n\n");


    int choice;
    do
    {
        printf("\n---Main Menu---\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Vehicle Management\n");
        printf("4. Delivery Request\n");
        printf("5. View All Deliveries\n");
        printf("6. Save Deliveries to File\n");
        printf("7. Load deliveries\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            cityManagement(citiesArr, &cityCount, distance);
            break;

        case 2:
            //inputOrEditDistance(distance, citiesArr, cityCount);

        {
            int distChoice;
            do
            {
                printf("\n--- DISTANCE MANAGEMENT ---\n");
                printf("1. Input/Edit Distance\n");
                printf("2. Display Distance Table\n");
                printf("3. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &distChoice);

                switch (distChoice)
                {
                case 1:
                    inputOrEditDistance(distance, citiesArr, cityCount);
                    break;
                case 2:
                    displayDistanceTable(distance, citiesArr, cityCount);
                    break;
                case 3:
                    break;
                default:
                    printf("Invalid choice!\n");
                }
            }
            while (distChoice != 3);
        }
        break;

        case 3:
            displayVehicles(vehicles);
            break;

        case 4:
            handleDeliveryRequest(citiesArr, cityCount, distance, vehicles, deliveries, &deliveryCount);
            break;

        case 5:
            viewAllDeliveries(citiesArr, deliveries, deliveryCount);
            break;

        case 6:
            saveDeliveriesToFile(deliveries, deliveryCount, citiesArr);
            break;

        case 7:
            loadDeliveriesFromFile(deliveries, &deliveryCount, citiesArr);
            break;


        case 8:
            printf("\nSaving deliveries before exit...\n");
            saveRoutesToFile(citiesArr, cityCount, distance);
            saveDeliveriesToFile(deliveries, deliveryCount, citiesArr);
            printf("\n Exiting program...\n");
            break;




        default:
            printf("Invalid choice!\n");
        }

    }
    while(choice != 8);

    printf("\nProgramme ended!\n");
    return 0;
}

