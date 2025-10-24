// city.c
#include <stdio.h>
#include <string.h>
#include "city.h"

void getCities(char cities[][30], int *cityCount)
{
    char temp[][30] =
    {
        "Anuradhapura", "Ampara", "Badulla", "Bandarawela", "Batticaloa"
        /*,"Colombo", "Dankotuwa", "Dambulla", "Deniyaya", "Eheliyagoda",
        "Gampaha", "Gampola", "Galle", "Halawatha", "Hambantota",
        "Ibbagamuwa", "Ja-Ela", "Jaffna", "Katunayaka", "Kalutara",
        "Kandy", "Katharagama", "Matara", "Mannar", "Polonnaruwa",
        "Ratnapura", "Thissa", "Tangalle", "Trincomalee", "Vavuniya"*/
    };

    int size = sizeof(temp) / sizeof(temp[0]);

    for (int i = 0; i < size; i++)
    {
        strcpy(cities[i], temp[i]);
    }
    *cityCount = size;      //store no. of cities
}

void displayCities(char cities[][30], int cityCount)
{
    if(cityCount == 0)
    {
        printf("No cities available.\n");
        return;
    }

    printf("\n---City List---\n");
    for(int i = 0; i < cityCount; i++)
    {
        printf("%2d.%s\n", i + 1, cities[i]);
    }
}



void addCity(char cities[][30], int *cityCount)
{
    if(*cityCount >= MAX_CITIES)
    {
        printf("City limit reached (max %d)!\n", MAX_CITIES);
        return;
    }


    char newCity[30];
    printf("New city name: ");
    scanf(" %[^\n]", newCity);

    for(int i = 0; i < *cityCount; i++)
    {
        if(strcmp(cities[i], newCity) == 0)
        {
            printf("City alread exist!\n");
            return;
        }
    }

    strcpy(cities[*cityCount], newCity);
    (*cityCount)++;
    printf("'%s' city added successfully!\n", newCity);

}

void removeCity(char cities[][30], int *cityCount)
{
    if(*cityCount == 0)
    {
        printf("No cities to remove.\n");
    }

    displayCities(cities, *cityCount);
    int index;
    printf("Enter city number to remove: ");
    scanf("%d", &index);

    if(index < 1 || index > *cityCount)
    {
        printf("Invalid number!\n");
        return;
    }

    for(int i = index - 1; i < *cityCount - 1; i++)
    {
        strcpy(cities[i], cities[i + 1]);

    }
    (*cityCount)--;

    printf("City removed successfully!\n");
}

void renameCity(char cities[][30], int cityCount)
{
    if(cityCount == 0)
    {
        printf("No cities to rename.\n");
        return;
    }

    displayCities(cities, cityCount);
    int index;
    printf("Enter city index to rename: ");
    scanf("%d", &index);

    if(index < 1 || index > cityCount)
    {
        printf("Invalid input\n");
        return;
    }

    char newName[30];
    printf("Enter the new name for '%s': ", cities[index - 1]);
    scanf(" %[^\n]", newName);

    strcpy(cities[index - 1], newName);
    printf("City renamed successfully!\n");

}



void cityManagement(char cities[][30], int *cityCount)
{

    int choice;
    do
    {
        printf("\n--- City Management System ---\n");
        printf("1. Display Cities\n");
        printf("2. Add a city\n");
        printf("3. Remove a city\n");
        printf("4. Rename a city\n");
        printf("5.Back to main menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayCities(cities, *cityCount);
            break;

        case 2:
            addCity(cities, cityCount);
            break;

        case 3:
            removeCity(cities, cityCount);
            break;

        case 4:
            renameCity(cities, *cityCount);
            break;

        case 5:
            printf("\nReturning to main menu...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    }
    while(choice != 5);

}

