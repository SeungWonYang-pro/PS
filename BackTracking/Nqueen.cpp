#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;

bool possible(int next, vector<int> cur)
{
    int flag = 0;
    int nextrow = cur.size();
    for (int i = 0; i < cur.size(); i++)
    {
        if (next == cur[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return false;
    }
    for (int i = 0; i < cur.size(); i++)
    {
        if (abs(nextrow - i) == abs(next - cur[i]))
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void sol(int n, vector<int> cur, vector<vector<int>> &ans, vector<int> visit)
{

    if (cur.size() == n)
    {
        if (n % 2 == 0)
        {
            if (cur[0] >= (n / 2))
            {
                return;
            }
        }
        ans.push_back(cur);
    }
    else
    {
        if (n % 2 == 0)
        {
            if (cur.size() >= 1)
            {
                if (cur[0] >= (n / 2))
                {
                    return;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {

            if (visit[i] == 0)
            {
                if (possible(i, cur))
                {
                    vector<int> nextvisit = visit;
                    nextvisit[i] = 1;
                    vector<int> temp = cur;
                    temp.push_back(i);
                    sol(n, temp, ans, nextvisit);
                }
            }
        }
    }

    return;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> answer;
    vector<int> cur;
    vector<int> visit(n, 0);
    sol(n, cur, answer, visit);
    if (n % 2 == 0)
    {
        printf("%d", (answer.size() * 2));
    }
    else
    {
        printf("%d", answer.size());
    }

    return 0;
}
