#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int matR, matC;
        scanf("%d %d", &matR, &matC);
        v.emplace_back(matR, matC);
    }

    int t = n - 1;
    long long ans = 0;
    long long **dp = new long long *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new long long[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = v[i].first * v[i].second * v[i + 1].second;
    }

    for (int k = 2; k < n; k++)
    {
        for (int i = 0; i < n - k; i++)
        {
            for (int j = i; j < i + k; j++)
            {
                if (j == i)
                {
                    dp[i][i + k] = dp[i][j] + dp[j + 1][i + k] + v[i].first * v[j].second * v[i + k].second;
                }
                else
                {
                    dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k] + v[i].first * v[j].second * v[i + k].second);
                }
            }
        }
    }

    printf("%lld", dp[0][n - 1]);

    for (int i = 0; i < n; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;

    return 0;
}
