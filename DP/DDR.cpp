#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    vector<int> v;
    int a;
    while (1)
    {
        scanf("%d", &a);
        if (a == 0)
        {
            break;
        }
        else
        {
            v.push_back(a);
        }
    }
    int **dp = new int *[20];
    
    for (int i = 0; i < 20; i++)
    {
        dp[i] = new int[v.size()];
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            dp[i][j] = -1;
        }
    }
    dp[v[0] - 1][0] = 2; // 0,v[0]
    dp[v[0] * 4][0] = 2; // v[0],0
    vector<pair<int, int>> vp;
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            if (i != j)
            {
                vp.emplace_back(i, j);
            }
        }
    }

    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (dp[j][i - 1] != -1)
            {
                pair<int, int> pre = vp[j];
                if (pre.first == v[i]) // 현재 밟고 있는 위치가 다음 칸이라면
                {
                    int nextC = dp[j][i - 1] + 1;
                    if (dp[j][i] == -1 || nextC < dp[j][i])
                    {
                        dp[j][i] = nextC;
                    }
                }
                else if (pre.second == v[i])
                {
                    int nextC = dp[j][i - 1] + 1;
                    if (dp[j][i] == -1 || nextC < dp[j][i])
                    {
                        dp[j][i] = nextC;
                    }
                }
                else
                {
                    int preL = pre.first;
                    int preR = pre.second;
                    if (preL != 0)
                    {
                        if ((abs(v[i] - preL) % 4) == 2)
                        {
                            int nextC = dp[j][i - 1] + 4;
                            int index;
                            for (int k = v[i] * 4; k < v[i] * 4 + 4; k++)
                            {
                                if (vp[k].second == pre.second)
                                {
                                    index = k;
                                    break;
                                }
                            }
                            if (dp[index][i] == -1 || nextC < dp[index][i])
                            {
                                dp[index][i] = nextC;
                            }
                        }
                        else if ((abs(v[i] - preL) % 4) == 1 || (abs(v[i] - preL) % 4) == 3)
                        {
                            int nextC = dp[j][i - 1] + 3;
                            int index;
                            for (int k = v[i] * 4; k < v[i] * 4 + 4; k++)
                            {
                                if (vp[k].second == pre.second)
                                {
                                    index = k;
                                    break;
                                }
                            }
                            if (dp[index][i] == -1 || nextC < dp[index][i])
                            {
                                dp[index][i] = nextC;
                            }
                        }
                    }
                    else
                    {
                        int nextC = dp[j][i - 1] + 2;
                        int index;
                        for (int k = v[i] * 4; k < v[i] * 4 + 4; k++)
                        {
                            if (vp[k].second == pre.second)
                            {
                                index = k;
                                break;
                            }
                        }
                        if (dp[index][i] == -1 || nextC < dp[index][i])
                        {
                            dp[index][i] = nextC;
                        }
                    }

                    if (preR != 0)
                    {
                        if ((abs(v[i] - preR) % 4) == 2)
                        {
                            int nextC = dp[j][i - 1] + 4;
                            int index;
                            for (int k = pre.first * 4; k < pre.first * 4 + 4; k++)
                            {
                                if (vp[k].second == v[i])
                                {
                                    index = k;
                                    break;
                                }
                            }
                            if (dp[index][i] == -1 || nextC < dp[index][i])
                            {
                                dp[index][i] = nextC;
                            }
                        }
                        else if ((abs(v[i] - preR) % 4) == 1 || (abs(v[i] - preR) % 4) == 3)
                        {
                            int nextC = dp[j][i - 1] + 3;
                            int index;
                            for (int k = pre.first * 4; k < pre.first * 4 + 4; k++)
                            {
                                if (vp[k].second == v[i])
                                {
                                    index = k;
                                    break;
                                }
                            }
                            if (dp[index][i] == -1 || nextC < dp[index][i])
                            {
                                dp[index][i] = nextC;
                            }
                        }
                    }
                    else
                    {
                        int nextC = dp[j][i - 1] + 2;
                        int index;
                        for (int k = pre.first * 4; k < pre.first * 4 + 4; k++)
                        {
                            if (vp[k].second == v[i])
                            {
                                index = k;
                                break;
                            }
                        }
                        if (dp[index][i] == -1 || nextC < dp[index][i])
                        {
                            dp[index][i] = nextC;
                        }
                    }
                }
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < 20; i++)
    {
        if (dp[i][v.size() - 1] != -1)
        {
            if (ans == -1 || ans > dp[i][v.size() - 1])
            {
                ans = dp[i][v.size() - 1];
            }
        }
    }
    printf("%d\n", ans);

    for (int i = 0; i < 20; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;

    return 0;
}
