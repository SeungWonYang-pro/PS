#include <iostream>
#include <cstdio>

using namespace std;

int findSet(int a, int *set)
{
    while (set[a] != a)
    {
        a = set[a];
    }
    return a;
}

if find (int a, int *set)
{
    if (a == set[a])
    {
        return a;
    }
    return set[a] = find(set[a], set);
}

void unionSet(int a, int b, int *set)
{
    int setA = findSet(a, set);
    int setB = findSet(b, set);
    if (setA != setB)
    {
        if (setA < setB)
        {
            set[setB] = setA;
        }
        else
        {
            set[setA] = setB;
        }
    }
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int *set = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        set[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int cmd, a, b;
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd == 0)
        {
            if (a != b)
            {
                unionSet(a, b, set);
            }
        }
        else if (cmd == 1)
        {
            if (a != b)
            {
                int setA = findSet(a, set);
                int setB = findSet(b, set);
                if (setA == setB)
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
            else
            {
                printf("YES\n");
            }
        }
    }

    delete[] set;

    return 0;
}
