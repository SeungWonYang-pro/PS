#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int
main(void)
{
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<vector<int>> buses(n + 1, vector<int>(n + 1, INT_MAX));
    vector<int> mincost(n + 1, INT_MAX);
    vector<vector<bool>> check(n + 1, vector<bool>(n + 1, false));
    vector<vector<bool>> visit(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; i++)
    {
        int st, dp, c;
        scanf("%d %d %d", &st, &dp, &c);
        if (buses[st][dp] > c)
        {
            buses[st][dp] = c;
            check[st][dp] = true;
        }
    }
    int start, target;
    scanf("%d %d", &start, &target);

    mincost[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> qu;

    for (int i = 0; i < buses[start].size(); i++)
    {
        if (check[start][i])
        {
            qu.push(make_pair(i, buses[start][i]));
            mincost[i] = buses[start][i];
            visit[start][i] = true;
        }
    }

    while (!qu.empty())
    {
        pair<int, int> cur = qu.top();
        qu.pop();

        for (int i = 0; i < buses[cur.first].size(); i++)
        {
            if (check[cur.first][i])
            {
                if (visit[cur.first][i] == false)
                {
                    visit[cur.first][i] = true;
                    int tempcost = mincost[cur.first] + buses[cur.first][i];
                    if (tempcost < mincost[i])
                    {
                        mincost[i] = tempcost;
                    }

                    qu.push(make_pair(i, mincost[i]));
                }
            }
        }
    }

    printf("%d", mincost[target]);

    return 0;
}
