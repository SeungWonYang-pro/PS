#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main(void)
{
    int n, k;
    vector<int> check(1000001, -1);
    vector<int> channel(10, 1);
    scanf("%d", &n);
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        int temp;
        scanf("%d", &temp);
        channel[temp] = 0;
    }

    int answer = 0;
    if (n == 100)
    {
        printf("%d", answer);
    }
    else
    {
        queue<int> qu;
        for (int i = 0; i < 10; i++)
        {
            if (channel[i] == 1)
            {
                qu.push(i);
                check[i] = 1;
            }
        }

        int flag = 0;
        while (!qu.empty() && flag == 0)
        {
            int cur = qu.front();
            if (cur >= n)
            {
                flag = 1;
            }
            qu.pop();
            for (int i = 0; i < 10; i++)
            {
                if (channel[i] == 1)
                {
                    if (cur < 100000)
                    {
                        if (check[cur * 10 + i] == -1)
                        {
                            check[cur * 10 + i] = check[cur] + 1;
                            qu.push((cur * 10 + i));
                        }
                    }
                }
            }
        }

        int min = -1;
        int max = -1;
        int checkflag = 0;
        int i = 0;
        while (checkflag == 0)
        {
            if (n - i >= 0)
            {
                if (check[n - i] != -1)
                {
                    min = n - i;
                    checkflag = 1;
                }
            }
            if ((n + i) < 1000001)
            {
                if (check[n + i] != -1)
                {
                    max = n + i;
                    checkflag = 1;
                }
            }
            ++i;
            if ((n - i) < 0 && (n + i) >= 1000001)
            {
                break;
            }
        }
        int nearnum;

        if (checkflag == 1)
        {
            if (min != -1)
            {
                nearnum = min;
            }
            else if (max != -1)
            {
                nearnum = max;
            }

            answer = 0;

            if (nearnum <= n)
            {
                answer = n - nearnum;
                answer += check[nearnum];
            }
            else
            {
                answer = nearnum - n;
                answer += check[nearnum];
            }

            int noremote;
            if (n >= 100)
            {
                noremote = n - 100;
            }
            else
            {
                noremote = 100 - n;
            }

            if (noremote < answer)
            {
                answer = noremote;
            }
        }
        else if (checkflag == 0)
        {
            if (n >= 100)
            {
                answer = n - 100;
            }
            else
            {
                answer = 100 - n;
            }
        }

        printf("%d\n", answer);
    }
    return 0;
}
