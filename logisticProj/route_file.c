// route_file.c
#include <stdio.h>
#include <string.h>
#include "route_file.h"

// Save cities and distance matrix to routes.txt
void saveRoutesToFile(char cities[][30], int cityCount,
                      int distance[MAX_CITIES][MAX_CITIES])
{
    FILE *fp = fopen("routes.txt", "w");
    if (!fp)
    {
        printf("Error: Cannot open routes.txt for writing!\n");
        return;
    }

    fprintf(fp, "%d\n", cityCount);

    for (int i = 0; i < cityCount; i++)
    {
        fprintf(fp, "%s\n", cities[i]);
    }

    for (int i = 0; i < cityCount; i++)
    {
        for (int j = 0; j < cityCount; j++)
        {
            fprintf(fp, "%d", distance[i][j]);
            if (j < cityCount - 1)
                fprintf(fp, " ");
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Routes saved successfully to routes.txt!\n");
}

// Load cities and distance matrix from routes.txt
int loadRoutesFromFile(char cities[][30], int *cityCount,
                       int distance[MAX_CITIES][MAX_CITIES])
{
    FILE *fp = fopen("routes.txt", "r");
    if (!fp)
    {
        printf("No previous route data found (routes.txt missing).\n");
        printf("Starting with default cities...\n");
        return 0;
    }


    if (fscanf(fp, "%d\n", cityCount) != 1)
    {
        printf("Error: Invalid format in routes.txt!\n");
        fclose(fp);
        return 0;
    }

    if (*cityCount < 0 || *cityCount > MAX_CITIES)
    {
        printf("Error: Invalid city count in routes.txt (%d)!\n", *cityCount);
        fclose(fp);
        return 0;
    }

    for (int i = 0; i < *cityCount; i++)
    {
        if (fgets(cities[i], 30, fp) == NULL)
        {
            printf("Error: Failed to read city name at line %d!\n", i + 2);
            fclose(fp);
            return 0;
        }
        // Remove newline character
        cities[i][strcspn(cities[i], "\n")] = '\0';
    }


    for (int i = 0; i < *cityCount; i++)
    {
        for (int j = 0; j < *cityCount; j++)
        {
            if (fscanf(fp, "%d", &distance[i][j]) != 1)
            {
                printf("Error: Failed to read distance at [%d][%d]!\n", i, j);
                fclose(fp);
                return 0;
            }
        }
    }

    fclose(fp);
    printf("Routes loaded successfully from routes.txt!\n");
    printf("%d cities and distance matrix loaded.\n", *cityCount);
    return 1;
}
