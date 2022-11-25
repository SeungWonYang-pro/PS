#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

void sol(int k, int m, vector<pair<int, int>> house, vector<pair<int, int>> chicken, vector<pair<int, int>> curchicken, int &ans)
{
    int answer = 0;
    if (curchicken.size() == m)
    {
        int dist = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int mini = 0;
            for (int j = 0; j < curchicken.size(); j++)
            {
                int temp = abs(curchicken[j].first - house[i].first) + abs(curchicken[j].second - house[i].second);
                if (j == 0)
                {
                    mini = temp;
                }
                else
                {
                    if (temp < mini)
                    {
                        mini = temp;
                    }
                }
            }
            dist = dist + mini;
        }
        if (ans > dist || ans == 0)
        {
            ans = dist;
        }
    }
    else
    {
        if (k == chicken.size())
        {
            return;
        }
        else
        {
            vector<pair<int, int>> newtemp = curchicken;
            curchicken.push_back(chicken[k]);
            sol(k + 1, m, house, chicken, curchicken, ans);
            sol(k + 1, m, house, chicken, newtemp, ans);
        }
    }

    return;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> city(n, vector<int>(n, 0));
    vector<pair<int, int>> chicken;
    vector<pair<int, int>> house;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &city[i][j]);
            if (city[i][j] == 1)
            {
                house.push_back(make_pair(i, j));
            }
            else if (city[i][j] == 2)
            {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    
    int ans = 0;
    vector<pair<int,int>> curchicken;
    sol(0, m, house, chicken, curchicken, ans);
    printf("%d\n",ans);

    return 0;
}
