#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#define MAX_NODE 50001

using namespace std;

struct Node
{
    int h;
    vector<int> ch;
};

int parent[MAX_NODE][18];

Node nodes[MAX_NODE];

bool check[MAX_NODE];
int main(void)
{
    int n;
    scanf("%d", &n);
    int max_level = (int)(floor(log2(n)));
    int a, b, temp;
    vector<vector<int>> v(n + 1, vector<int>());
    parent[1][0] = 1;
    nodes[1].h = 1;
    for (int i = 1; i <= n; i++)
    {
        check[i] = false;
    }
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    check[1] = true;
    int cur, tmp;
    int child;
    while (!q.empty())
    {
        cur = q.front();

        for (int i = 0; i < v[cur].size(); i++)
        {
            child = v[cur][i];
            if (check[child] == false)
            {
                check[child] = true;
                nodes[child].h = nodes[cur].h + 1;
                parent[child][0] = cur;
                for (int j = 1; j <= max_level; j++)
                {
                    tmp = parent[child][j - 1];
                    parent[child][j] = parent[tmp][j - 1];
                }
                q.push(child);
            }
        }
        q.pop();
    }
    int m;

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        if (nodes[a].h > nodes[b].h)
        {
            swap(a, b);
        }

        for (int j = max_level; j >= 0; j--)
        {
            if (nodes[parent[b][j]].h >= nodes[a].h)
            {
                b = parent[b][j];
            }
        }

        int ans = a;
        if (b == a)
        {
            printf("%d\n", a);
        }
        else
        {
            for (int j = max_level; j >= 0; j--)
            {
                if (parent[a][j] != parent[b][j])
                {
                    a = parent[a][j];
                    b = parent[b][j];
                }
                ans = parent[a][j];
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}
