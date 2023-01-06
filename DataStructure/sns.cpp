#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    bool *leaf = new bool[n];
    bool *check = new bool[n];
    vector<vector<int>> v(n, vector<int>());
    int *numF = new int[n];

    for (int i = 0; i < n; i++)
    {
        numF[i] = 0;
        leaf[i] = false;
        check[i] = false;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        numF[a]++;
        numF[b]++;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (numF[i] == 1)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front(); // leaf를 담음
        check[cur] = true;
        int adj = -1;

        for (int i = 0; i < v[cur].size(); i++)
        {
            if (check[v[cur][i]] == false)
            {
                adj = v[cur][i];
            }
        }
        if (adj == -1)
        {
            q.pop();
            continue;
        }
        if (check[adj] == false)
        {
            ans++;
            check[adj] = true;
            for (int j = 0; j < v[adj].size(); j++)
            {
                if (check[v[adj][j]] == false)
                {
                    numF[v[adj][j]]--;
                    if (numF[v[adj][j]] == 1)
                    {
                        q.push(v[adj][j]);
                    }
                }
                else
                {
                    numF[v[adj][j]]--;
                    v[adj].erase(v[adj].begin() + j);
                    j--;
                }
            }
        }

        q.pop();
    }

    printf("%d", ans);

    return 0;
}
