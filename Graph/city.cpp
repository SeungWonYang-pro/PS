#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef struct n
{
    int x, y;
    int cost;
} node;

struct cmp
{
    bool operator()(node a, node b)
    {
        return a.cost > b.cost;
    }
};

int findParent(int a, int *set)
{
    if (set[a] == a)
    {
        return a;
    }

    return set[a] = findParent(set[a], set);
}

int main(void)
{
    int n, m;
    priority_queue<node, vector<node>, cmp> pq;
    scanf("%d %d", &n, &m);
    int *set = new int[n];
    bool *check = new bool[n];
    for (int i = 0; i < n; i++)
    {
        set[i] = i;
        check[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        node temp;
        scanf("%d %d %d", &temp.x, &temp.y, &temp.cost);
        temp.x = temp.x - 1;
        temp.y = temp.y - 1;
        pq.push(temp);
    }

    int maxedgecost = -1;
    int curedgenum = 0;
    int mst = 0;
    while (!pq.empty())
    {
        node cur = pq.top();

        int Px = findParent(cur.x, set);
        int Py = findParent(cur.y, set);

        if (Px != Py)
        {
            if (Px > Py)
            {
                set[Px] = Py;
            }
            else
            {
                set[Py] = Px;
            }
            if (maxedgecost < cur.cost)
            {
                maxedgecost = cur.cost;
            }
            mst = mst + cur.cost;
            curedgenum++;
            check[cur.x] = true;
            check[cur.y] = true;
        }

        if (curedgenum == n - 1)
        {
            break;
        }
        pq.pop();
    }

    printf("%d", mst - maxedgecost);
    delete[] set;

    return 0;
}
