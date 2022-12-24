#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int *indegree = new int[n];
    vector<vector<int>> adj(n, vector<int>());
    vector<bool> check(n, false);
    int a, b;
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            check[i] = true;
        }
    }

    while (!q.empty())
    {
        int curnum = q.front();
        ans.push_back(curnum);
        for (int i = 0; i < adj[curnum].size(); i++)
        {
            if (check[adj[curnum][i]] == false)
            {
                indegree[adj[curnum][i]]--;

                if (indegree[adj[curnum][i]] == 0)
                {
                    q.push(adj[curnum][i]);
                    check[adj[curnum][i]] = true;
                }
            }
        }

        q.pop();
    }

    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]+1);
    }

    delete[] indegree;
    return 0;
}
