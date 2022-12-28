#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    int T;

    scanf("%d", &T);

    int n;
    int k;
    while (T > 0)
    {
        scanf("%d %d", &n, &k);
        int *time = new int[n];
        int *indegree = new int[n];
        vector<vector<int>> adj(n, vector<int>());
        bool *check = new bool[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &time[i]);
            indegree[i] = 0;
            check[i] = false;
        }
        int a, b;
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            indegree[b]++;
            adj[a].push_back(b);
        }
        int target;
        scanf("%d", &target);
        target--;
        queue<pair<int, int>> q;

        int *timeMin = new int[n];
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                timeMin[i] = 0;
                q.push(make_pair(i, time[i]));
                check[i] = true;
            }
            else
            {
                timeMin[i] = INT_MIN;
            }
        }

        int sumT = 0;
        int lastStep;
        while (!q.empty())
        {
            pair<int, int> curN = q.front();

            if (curN.first == target)
            {
                sumT = curN.second;
                break;
            }

            for (int i = 0; i < adj[curN.first].size(); i++)
            {
                if (check[adj[curN.first][i]] == false)
                {
                    indegree[adj[curN.first][i]]--;
                    if (timeMin[adj[curN.first][i]] < curN.second)
                    {
                        timeMin[adj[curN.first][i]] = curN.second;
                    }
                    if (indegree[adj[curN.first][i]] == 0)
                    {
                        q.push(make_pair(adj[curN.first][i], timeMin[adj[curN.first][i]] + time[adj[curN.first][i]]));
                        check[adj[curN.first][i]] = true;
                    }
                }
            }

            q.pop();
        }

        printf("%d\n", sumT);
        delete[] time;
        delete[] timeMin;
        delete[] indegree;
        delete[] check;
        T--;
    }

    return 0;
}
