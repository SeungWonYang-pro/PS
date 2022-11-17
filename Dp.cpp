#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> table(n, vector<int>(n, 0));
    vector<vector<int>> sumrow(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &table[i][j]);
            sum = sum + table[i][j];
            sumrow[i][j] = sum;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int fr, fc, lr, lc;
        scanf("%d %d %d %d", &fr, &fc, &lr, &lc);
        --fr;
        --fc;
        --lr;
        --lc;
        int sum = 0;
        if (fc != 0)
        {
            for (int j = fr; j <= lr; j++)
            {
                sum = sum + (sumrow[j][lc] - sumrow[j][fc - 1]);
            }
        }
        else
        {
            for (int j = fr; j <= lr; j++)
            {
                sum = sum + sumrow[j][lc];
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
