#include <stdio.h>
#include <string.h>
#include "city.h"


int main()
{
    char citiesArr[MAX_CITIES][30];
    int cityCount = 0;

    getCities(citiesArr, &cityCount);
    cityManagement(citiesArr, &cityCount);

    printf("\nProgramme ended!\n");

    return 0;
}

