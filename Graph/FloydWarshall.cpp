#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void)
{
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);
    int **mincost = new int *[n];

    for (int i = 0; i < n; i++)
    {
        mincost[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                mincost[i][j] = -1;
            }
            else
            {
                mincost[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a = a - 1;
        b = b - 1;
        if (c < mincost[a][b] || mincost[a][b] == -1)
        {
            mincost[a][b] = c;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (j != k && i != k)
                {
                    if (mincost[i][k] != -1 && mincost[k][j] != -1)
                    {
                        if (mincost[i][j] == -1 || mincost[i][j] > (mincost[i][k] + mincost[k][j])) // k 를 거쳐간다.
                        {
                            mincost[i][j] = mincost[i][k] + mincost[k][j];
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mincost[i][j] == -1)
            {
                mincost[i][j] = 0;
            }
            printf("%d ", mincost[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        delete[] mincost[i];
    }

    delete[] mincost;

    return 0;
}
