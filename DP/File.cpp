#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);

    while (T > 0)
    {
        int n;
        scanf("%d", &n);
        vector<int> v;
        int *nums = new int[n];
        int *sum = new int[n];
        int **DP = new int *[n];
        for (int i = 0; i < n; i++)
        {
            DP[i] = new int[n];
            scanf("%d", &nums[i]);
            if (i == 0)
            {
                sum[i] = nums[i];
            }
            else
            {
                sum[i] = sum[i - 1] + nums[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                DP[i][j] = 0;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            DP[i][i + 1] = nums[i] + nums[i + 1];
        }

        for (int k = 2; k < n; k++)
        {
            for (int i = 0; i < n - k; i++)
            {
                for (int j = i; j < i + k; j++)
                {
                    if (j == i)
                    {
                        if (i == 0)
                        {
                            DP[i][i + k] = DP[i + 1][i + k] + sum[i + k];
                        }
                        else
                        {
                            DP[i][i + k] = DP[i + 1][i + k] + sum[i + k] - sum[i - 1];
                        }
                    }
                    else
                    {
                        if (i != 0)
                        {
                            DP[i][i + k] = min(DP[i][i + k], DP[i][j] + DP[j + 1][i + k] + sum[i + k] - sum[i - 1]);
                        }
                        else
                        {
                            DP[i][i + k] = min(DP[i][i + k], DP[i][j] + DP[j + 1][i + k] + sum[i + k]);
                        }
                    }
                }
            }
        }

        printf("%d\n", DP[0][n - 1]);

        for (int i = 0; i < n; i++)
        {
            delete[] DP[i];
        }

        delete[] nums;
        delete[] DP;
        T--;
    }

    return 0;
}
