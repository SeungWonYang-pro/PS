#include <iostream>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first > b.first;
    }
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> v;
    int **costs = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        costs[i] = new int[10001];
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        int b = 0;
        scanf("%d", &a);
        v.emplace_back(a, b);
    }
    for (int i = 0; i < 10001; i++)
    {
        costs[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        costs[i][0] = 0;
    }
    int maxC = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i].second);
        maxC = maxC + v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    int sumC = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxC; j++)
        {
            costs[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxC; j++)
        {
            if (j >= v[i - 1].second) // 새 물건 비용보다 클 때 비교
            {
                if (j != 0)
                {
                    costs[i][j] = max(costs[i - 1][j], costs[i - 1][j - v[i - 1].second] + v[i - 1].first);
                }
                else
                {
                    costs[i][j] = costs[i - 1][j] + v[i - 1].first;
                }
            }
            else
            {
                if (j != 0)
                {
                    costs[i][j] = costs[i - 1][j];
                }
                else
                {
                    costs[i][j] = costs[i - 1][j];
                }
            }
        }
    }

    int ans = -1;

    for (int i = 0; i <= maxC; i++)
    {
        if (costs[n][i] >= m)
        {
            ans = i;
            break;
        }
    }
    printf("%d\n",ans);

    return 0;
}
