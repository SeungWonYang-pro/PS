#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int bfs(int n, int m, vector<vector<int>> map)
{
    int num = 0;
    queue<pair<int, int>> qu;
    vector<vector<bool>> check(map.size(), vector<bool>(map[0].size(), false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (map[i][j] == 2)
            {
                qu.push(make_pair(i, j));
                check[i][j] = true;
            }
        }
    }

    vector<pair<int, int>> move;
    move.push_back(make_pair(1, 0));
    move.push_back(make_pair(-1, 0));
    move.push_back(make_pair(0, 1));
    move.push_back(make_pair(0, -1));
    while (!qu.empty())
    {
        pair<int, int> cur = qu.front();
        qu.pop();

        for (int i = 0; i < move.size(); i++)
        {
            int nextr = cur.first + move[i].first;
            int nextc = cur.second + move[i].second;
            if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < m)
            {
                if (check[nextr][nextc] == false)
                {
                    check[nextr][nextc] = true;
                    if (map[nextr][nextc] == 0)
                    {
                        map[nextr][nextc] = 2;
                        qu.push(make_pair(nextr, nextc));
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                num++;
            }
        }
    }

    return num;
}

void sol(int n, int m, int nofwall, int &ans, vector<vector<int>> map, int cur, vector<pair<int, int>> blank)
{
    if (nofwall == 3)
    {
        int curSafe = bfs(n, m, map);
        if (ans < curSafe || ans == -1)
        {
            ans = curSafe;
        }
    }
    else
    {
        if (cur < blank.size())
        {
            vector<vector<int>> newmap = map;
            int nextr = blank[cur].first;
            int nextc = blank[cur].second;
            cur++;
            newmap[nextr][nextc] = 1;
            int nextnofwall = nofwall + 1;
            sol(n, m, nextnofwall, ans, newmap, cur, blank);
            sol(n, m, nofwall, ans, map, cur, blank);
        }
    }

    return;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<pair<int, int>> blank;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0)
            {
                blank.push_back(make_pair(i, j));
            }
        }
    }

    int nofwall = 0;
    int cur = 0;
    int ans = -1;
    sol(n, m, nofwall, ans, map, cur, blank);

    
    
    printf("%d", ans);

    return 0;
}
