#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct cmp
{

    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int main(void)
{
    int n, m, start;
    scanf("%d %d", &n, &m);
    scanf("%d", &start);
    start = start - 1;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    vector<bool> check(n, false);

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        x = x - 1;
        y = y - 1;
        graph[x].emplace_back(y, w);
    }

    vector<bool> visit(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<int> answer(n, -1);
    answer[start] = 0;
    pq.push(make_pair(start, 0));

    while (!pq.empty())
    {
        int curnode = pq.top().first;
        int curcost = pq.top().second;
        pq.pop();
        if (visit[curnode] == false)
        {
            visit[curnode] = true;

            for (int i = 0; i < graph[curnode].size(); i++)
            {
                if (visit[graph[curnode][i].first] == false)
                {
                    int temp = curcost + graph[curnode][i].second;
                    if (answer[graph[curnode][i].first] == -1)
                    {
                        answer[graph[curnode][i].first] = temp;
                        pq.push(make_pair(graph[curnode][i].first, temp));
                    }
                    else
                    {
                        if (answer[graph[curnode][i].first] > temp)
                        {
                            answer[graph[curnode][i].first] = temp;
                            pq.push(make_pair(graph[curnode][i].first, temp));
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] == -1)
        {
            printf("INF\n");
        }
        else
        {
            printf("%d\n", answer[i]);
        }
    }

    return 0;
}
