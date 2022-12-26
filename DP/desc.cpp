#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <stack>

using namespace std;

int **map;
int mr[4] = {1, -1, 0, 0};
int mc[4] = {0, 0, 1, -1};
int **memomap;

int sol(int a, int b, int n, int m, int &ans)
{

    if ((a == n - 1 && b == m - 1))
    {
        return 1;
    }

    if (memomap[a][b] != -1)
    {
        return memomap[a][b];
    }

    if (memomap[a][b] == -1)
    {
        memomap[a][b] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nextr = a + mr[i];
            int nextc = b + mc[i];
            if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < m)
            {

                if (map[nextr][nextc] < map[a][b])
                {
                    memomap[a][b] += sol(nextr, nextc, n, m, ans);
                }
            }
        }
    }

    return memomap[a][b];
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    map = new int *[n];
    memomap = new int *[n];
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[m];
        memomap[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
            memomap[i][j] = -1;
        }
    }

    int ans = 0;
    ans = sol(0, 0, n, m, ans);

    printf("%d", ans);

    for (int i = 0; i < n; i++)
    {
        delete[] map[i];
        delete[] memomap[i];
    }

    delete[] map;
    delete[] memomap;

    return 0;
}
