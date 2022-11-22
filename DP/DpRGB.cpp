#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> cost(n, vector<int>(3, 0));
    vector<vector<int>> minCost(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

  
    minCost[0][0] = cost[0][0];
    minCost[0][1] = cost[0][1];
    minCost[0][2] = cost[0][2];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < minCost[i].size(); j++)
        {
            if (j == 0)
            {
                minCost[i][j] = min(minCost[i - 1][1], minCost[i - 1][2]) + cost[i][j];
            }
            else if (j == 1)
            {
                minCost[i][j] = min(minCost[i - 1][0], minCost[i - 1][2]) + cost[i][j];
            }
            else if (j == 2)
            {
                minCost[i][j] = min(minCost[i - 1][0], minCost[i - 1][1]) + cost[i][j];
            }
        }
    }

    int answer =min(min(minCost[n-1][0],minCost[n-1][1]), minCost[n-1][2]);

    printf("%d",answer);

    return 0;
}
