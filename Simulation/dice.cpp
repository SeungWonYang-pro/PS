#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void rolldiceNS(int *dv, int cmd)
{
    if (cmd == 2) // 북
    {
        for (int i = 3; i > 0; i--)
        {
            swap(dv[i], dv[i - 1]);
        }
    }
    else if (cmd == 3) // 남
    {
        for (int i = 0; i < 3; i++)
        {
            swap(dv[i], dv[i + 1]);
        }
    }
}

void rolldiceEW(int *dv, int *dh, int cmd)
{
    if (cmd == 0) // 동쪽
    {
        swap(dh[0], dv[3]);
        swap(dh[1], dv[1]);
        swap(dh[0], dh[1]);
    }
    else if (cmd == 1) // 서쪽
    {
        swap(dh[0], dv[1]);
        swap(dh[1], dv[3]);
        swap(dh[0], dh[1]);
    }
}

int main(void)
{
    int n, m, x, y, k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    int **map = new int *[n];
    int *dice = new int[6];
    int *dv = new int[4];
    int *dh = new int[2];
    dv[0] = 1;
    dv[1] = 0; // 밑
    dv[2] = 4;
    dv[3] = 5;
    dh[0] = 3;
    dh[1] = 2;
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[m];
    }

    for (int i = 0; i < 6; i++)
    {
        dice[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    int cmd;
    int mr[4] = {0, 0, -1, +1};
    int cur = 0;
    int mc[4] = {1, -1, 0, 0};
    int nextr, nextc;
    while (k > 0)
    {
        scanf("%d", &cmd);
        cmd--;
        nextr = x + mr[cmd];
        nextc = y + mc[cmd];

        if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < m)
        {
            if (cmd == 0) // 동쪽
            {
                rolldiceEW(dv, dh, cmd);
            }
            else if (cmd == 1) // 서쪽
            {
                rolldiceEW(dv, dh, cmd);
            }
            else if (cmd == 2) // 북쪽
            {
                rolldiceNS(dv, cmd);
            }
            else if (cmd == 3) // 남쪽
            {
                rolldiceNS(dv, cmd);
            }
            x = nextr;
            y = nextc;
            if (map[x][y] == 0)
            {
                map[x][y] = dice[dv[1]];
            }
            else
            {
                dice[dv[1]] = map[x][y];
                map[x][y] = 0;
            }
            printf("%d\n", dice[dv[3]]);
        }

        k--;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] map[i];
    }
    delete[] map;
    delete[] dv;
    delete[] dh;
    delete[] dice;
    return 0;
}
