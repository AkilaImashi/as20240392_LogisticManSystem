#include <stdio.h>
#include <string.h>
#include "city.h"
#include "distance.h"
#include "vehicle.h"


int main()
{
    char citiesArr[MAX_CITIES][30];
    int cityCount = 0;
    int distance[MAX_CITIES][MAX_CITIES];
    Vehicle vehicles[VEHICLE_COUNT];

    //initialize data
    getCities(citiesArr, &cityCount);
    //cityManagement(citiesArr, &cityCount);

    initializeDistance(distance, cityCount);
    initializeVehicles(vehicles);

    int choice;
    do
    {
        printf("\n---Main Menu---\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Vehicle Management\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            cityManagement(citiesArr, &cityCount);
            break;

        case 2:
           inputOrEditDistance(distance, citiesArr, cityCount);

        /*{
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
        }*/
        break;

        case 3:
            displayVehicles(vehicles);
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    }
    while(choice != 4);

    printf("\nProgramme ended!\n");

    return 0;
}

