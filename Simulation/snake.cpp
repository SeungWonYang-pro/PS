#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int move(int **snakemap, queue<pair<int, int>> &snake, int **map, int flag, int n)
{
    int nextr = snake.back().first;
    int nextc = snake.back().second;
    if (flag == 0) // 오른
    {
        nextc = nextc + 1;
    }
    else if (flag == 1) // 아래
    {
        nextr = nextr + 1;
    }
    else if (flag == 2) // 왼
    {
        nextc = nextc - 1;
    }
    else if (flag == 3) // 위
    {
        nextr = nextr - 1;
    }

    if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < n)
    {
        if (snakemap[nextr][nextc] == 0)
        {
            if (map[nextr][nextc] == 1)
            {
                map[nextr][nextc] = 0;
                snakemap[nextr][nextc] = 1;
                snake.push(make_pair(nextr, nextc));
            }
            else
            {
                snakemap[nextr][nextc] = 1;
                snake.push(make_pair(nextr, nextc));
                snakemap[snake.front().first][snake.front().second] = 0;
                snake.pop();
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int **map = new int *[n];
    int **snakemap = new int *[n];
    vector<pair<int, int>> cmd;
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[n];
        snakemap[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = 0;
            snakemap[i][j] = 0;
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a - 1][b - 1] = 1;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int c;
        char temp;
        scanf("%d %c", &c, &temp);
        if (temp == 'L')
        {
            cmd.push_back(make_pair(c, 1)); // 왼쪽 : 1
        }
        else if (temp == 'D')
        {
            cmd.push_back(make_pair(c, 2)); // 오른쪽 : 2
        }
    }
    queue<pair<int, int>> snake;
    snake.push(make_pair(0, 0));
    int ans = 0;
    int flag = 0; // 0: 오른쪽 1: 아래 2: 왼쪽 3: 위
    int check;
    snakemap[0][0] = 1;
    while (1)
    {
        if (cmd.size() > 0)
        {
            if (cmd[0].first == ans)
            {
                if (cmd[0].second == 1)
                {
                    flag = flag - 1;
                    if (flag < 0)
                    {
                        flag = flag + 4;
                    }
                }
                else if (cmd[0].second == 2)
                {
                    flag = flag + 1;
                    if (flag >= 4)
                    {
                        flag = flag - 4;
                    }
                }
                cmd.erase(cmd.begin());
            }
        }
        check = move(snakemap, snake, map, flag, n);
        ans++;

        if (check == 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] map[i];
        delete[] snakemap[i];
    }

    printf("%d", ans);
    delete[] map;
    delete[] snakemap;
    return 0;
}
