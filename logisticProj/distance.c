//distance.c
#include <stdio.h>
#include "distance.h"
#include "city.h"

void initializeDistance(int distance[MAX_CITIES][MAX_CITIES], int cityCount)
{
    for(int i = 0; i < cityCount; i++)
    {
        for(int j = 0; j < cityCount; j++)
        {
            if(i == j)
                distance[i][j] = 0;

            else
                distance[i][j] = -1;
        }
    }
}

void inputOrEditDistance(int distance[MAX_CITIES][MAX_CITIES], char cities[][30], int cityCount)
{
    int city1, city2, dist;

    printf("\n---Enter or Edit Distance between cities---\n");
    for(int i = 0; i < cityCount; i++)
    {
        printf("%2d. %s\n", i + 1, cities[i]);
    }

    printf("\nEnter first city number: ");
    scanf("%d", &city1);
    printf("Enter second city number: ");
    scanf("%d", &city2);

    if(city1 < 1 || city1 > cityCount || city2 < 1 || city2 > cityCount)
    {
        printf("Invalid city number !\n");
        return;
    }

    if(city1 == city2)
    {
        printf("You entered the same city for both inputs!\n");
        return;
    }

    printf("Enter distance between %s and %s (in km): ", cities[city1 - 1], cities[city2 - 1]);
    scanf("%d", &dist);

    distance[city1 - 1][city2 - 1] = dist;
    distance[city2 - 1][city1 - 1] = dist;

    printf("Distance updated successfully!\n");

}

void displayDistanceTable(int distance[MAX_CITIES][MAX_CITIES], char cities[][30], int cityCount)
{
    if(cityCount == 0)
    {
        printf("No cities available to display\n ");
        return;
    }

    printf("\n-----Distance Table-----\n");
    printf("%15s", " ");

    for(int i = 0; i < cityCount; i++)
    {
        printf("%15s", cities[i]);
    }
    printf("\n");

    for(int i = 0; i < cityCount; i ++)
    {
        printf("%15s", cities[i]);

        for(int j = 0; j < cityCount; j++)
        {
            //printf("%15s", cities[i]);
            if(distance[i][j] == -1)
                printf("%15s","-");
            else
                printf("%15d", distance[i][j]);
        }
        printf("\n");


    }
    printf("======================================================\n");


}
