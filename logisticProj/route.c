// route.c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "route.h"

#define INF 999999

// using Dijkstra's algorithm to find shortest distance
int findLeastDistance(int distance[MAX_CITIES][MAX_CITIES], int cityCount,
                      int src, int dest, int path[], int *pathLen)
{
    int dist[MAX_CITIES];
    bool visited[MAX_CITIES];
    int prev[MAX_CITIES];

    for (int i = 0; i < cityCount; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        prev[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < cityCount - 1; count++)
    {
        int minDist = INF, u = -1;
        for (int i = 0; i < cityCount; i++)
        {
            if (!visited[i] && dist[i] <= minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < cityCount; v++)
        {
            if (!visited[v] && distance[u][v] > 0 && distance[u][v] < INF)
            {
                if (dist[u] + distance[u][v] < dist[v])
                {
                    dist[v] = dist[u] + distance[u][v];
                    prev[v] = u;
                }
            }
        }
    }

    // Build path
    int len = 0;
    for (int v = dest; v != -1; v = prev[v])
        path[len++] = v;

    // Reverse path
    for (int i = 0; i < len / 2; i++)
    {
        int temp = path[i];
        path[i] = path[len - i - 1];
        path[len - i - 1] = temp;
    }

    *pathLen = len;
    return dist[dest];
}


// Display the route nicely
void displayRoute(char cities[][30], int path[], int pathLen, int minDist)
{
    printf("\n--- Least-Distance Route ---\n");
    for (int i = 0; i < pathLen; i++)
    {
        printf("%s", cities[path[i]]);
        if (i != pathLen - 1) printf(" -> ");
    }
    printf("\nMinimum Distance: %d km\n", minDist);
    printf("-----------------------------\n");
}

