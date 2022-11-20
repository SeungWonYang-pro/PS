#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> pic(n, vector<int>(n, 0));
    vector<vector<int>> rbpic(n, vector<int>(n, 0));
    vector<vector<int>> check(n, vector<int>(n, 0));
    vector<vector<int>> rbcheck(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        getchar();
        for (int j = 0; j < n; j++)
        {
            char c;

            scanf("%c", &c);
            if (c == 'R')
            {
                pic[i][j] = 1;
                rbpic[i][j] = 1;
            }
            else if (c == 'G')
            {
                pic[i][j] = 2;
                rbpic[i][j] = 1;
            }
            else if (c == 'B')
            {
                pic[i][j] = 3;
                rbpic[i][j] = 3;
            }
        }
    }

    int place = 1;

    queue<pair<int, int>> qu;

    vector<pair<int, int>> move;
    move.push_back(make_pair(1, 0));
    move.push_back(make_pair(-1, 0));
    move.push_back(make_pair(0, 1));
    move.push_back(make_pair(0, -1));
    qu.push(make_pair(0, 0));
    check[0][0] = place;
    bool finish = false;
    int flag = 0;
    while (!qu.empty() || finish != true)
    {
        int curr, curc;

        if (!qu.empty())
        {
            curr = qu.front().first;
            curc = qu.front().second;
            qu.pop();
        }
        else
        {
            place = place + 1;
            flag = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (check[i][j] == 0)
                    {
                        check[i][j] = place;
                        curr = i;
                        curc = j;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    break;
                }
            }
            if (flag == 0)
            {
                finish = true;
                break;
            }
        }
        for (int i = 0; i < move.size(); i++)
        {
            int newr = curr + move[i].first;
            int newc = curc + move[i].second;
            if (newr >= 0 && newr < n && newc >= 0 && newc < n)
            {
                if (check[newr][newc] == 0)
                {
                    if (pic[newr][newc] == pic[curr][curc])
                    {
                        check[newr][newc] = check[curr][curc];
                        qu.push(make_pair(newr, newc));
                    }
                }
            }
        }
    }

    int answer1 = place - 1;
    while (!qu.empty())
    {
        qu.pop();
    }

    place = 1;
    qu.push(make_pair(0, 0));
    rbcheck[0][0] = place;
    finish = false;
    flag = 0;
    while (!qu.empty() || finish != true)
    {
        int curr, curc;

        if (!qu.empty())
        {
            curr = qu.front().first;
            curc = qu.front().second;
            qu.pop();
        }
        else
        {
            place = place + 1;
            flag = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (rbcheck[i][j] == 0)
                    {
                        rbcheck[i][j] = place;
                        curr = i;
                        curc = j;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    break;
                }
            }
            if (flag == 0)
            {
                finish = true;
                break;
            }
        }
        for (int i = 0; i < move.size(); i++)
        {
            int newr = curr + move[i].first;
            int newc = curc + move[i].second;
            if (newr >= 0 && newr < n && newc >= 0 && newc < n)
            {
                if (rbcheck[newr][newc] == 0)
                {
                    if (rbpic[newr][newc] == rbpic[curr][curc])
                    {
                        rbcheck[newr][newc] = rbcheck[curr][curc];
                        qu.push(make_pair(newr, newc));
                    }
                }
            }
        }
    }

    
    int answer2 = place - 1;

    printf("%d %d", answer1, answer2);
    return 0;
}
