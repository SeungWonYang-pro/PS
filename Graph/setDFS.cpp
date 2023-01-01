#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

bool isCycle(int *teams, bool *isVisited, bool *check, int cur, int n)
{
    set<int> a;
    a.insert(cur);
    isVisited[cur] = true;
    int temp = teams[cur];
    int flag = 0;
    while (1)
    {
        if (a.find(teams[temp]) != a.end())
        {
            flag = 1;
            break;
        }
        else if (check[temp] == true)
        {
            flag = 2;
            break;
        }

        a.insert(temp);
        isVisited[temp] = true;
        temp = teams[temp];
    }

    int firstValue = temp;

    if (flag == 1)
    {
        int trueFlag = 0;
        for (;;)
        {
            if (temp == cur)
            {
                trueFlag = 1;
            }
            if (check[temp] != firstValue && check[temp] != true)
            {
                check[temp] = true;
                temp = teams[temp];
            }
            else
            {
                break;
            }
        }
        if (trueFlag == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int sol(int *teams, int n)
{
    bool *check = new bool[n];
    int ans = 0;
    bool *isVisited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        check[i] = false;
        isVisited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (check[i] == false)
        {
            if (isVisited[i] == false)
            {
                if (!isCycle(teams, isVisited, check, i, n))
                {

                    ans++;
                }
            }
            else
            {
                ans++;
            }
            check[i] = true;
        }
    }

    return ans;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T > 0)
    {
        int n;
        scanf("%d", &n);
        int *teams = new int[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &teams[i]);
            teams[i]--;
        }
        int ans = sol(teams, n);

        printf("%d\n", ans);
        T--;
    }
    return 0;
}
