#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int main(void)
{
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    int **road = new int *[n];
    for (int i = 0; i < n; i++)
    {
        road[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            road[i][j] = INT_MAX;
        }
    }

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        a = a - 1;
        b = b - 1;
        if (road[a][b] > c)
        {
            road[a][b] = c;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (road[i][k] != INT_MAX && road[k][j] != INT_MAX)
                    {
                        road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
                    }
                }
            }
        }
    }
    int cost;
    int maxcost = -1;
    for (int i = 0; i < n; i++)
    {
        if (i != x - 1)
        {
            cost = road[i][x - 1] + road[x - 1][i];
            if (maxcost == -1 || maxcost < cost)
            {
                maxcost = cost;
            }
        }
    }

    printf("%d", maxcost);
    for (int i = 0; i < n; i++)
    {
        delete[] road[i];
    }
    delete[] road;

    return 0;
}
