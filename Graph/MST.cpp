#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int findParent(int a, int *numset)
{
    while (numset[a] != a)
    {
        a = numset[a];
    }
    return a;
}

void unionSet(int a, int b, int *numset)
{
    int aParent = findParent(a, numset);
    int bParent = findParent(b, numset);
    if (aParent != bParent)
    {
        numset[bParent] = aParent;
    }
}

typedef struct e
{
    int a, b; //  (a -> b  )
    int cost; // cost
} edge;

struct cmp
{
    bool operator()(edge a, edge b)
    {
        return (a.cost > b.cost);
    }
};
int main(void)
{
    int V, E;
    scanf("%d %d", &V, &E);
    int *numset = new int[V]; //집합 표현 각 수의 부모 노드 인덱스를 담고있다
    for (int i = 0; i < V; i++)
    {
        numset[i] = i;
    }

    priority_queue<edge, vector<edge>, cmp> q;

    for (int i = 0; i < E; i++)
    {
        edge temp;
        scanf("%d %d %d", &temp.a, &temp.b, &temp.cost);
        temp.a = temp.a - 1;
        temp.b = temp.b - 1;
        q.push(temp);
    }

    int ans = 0;

    int edgenum = 0;
    int cnt = 5;
    while (edgenum != V - 1)
    {
        edge cur = q.top();
        int curAparent = findParent(cur.a, numset);
        int curBparent = findParent(cur.b, numset);

        if (curAparent != curBparent)
        {
            ans = ans + cur.cost;
            unionSet(cur.a, cur.b, numset);
            edgenum++;
        }
        q.pop();
    }

    printf("%d", ans);
    delete[] numset;

    return 0;
}
