#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int mr[4] = {1, -1, 0, 0};
int mc[4] = {0, 0, 1, -1};
int **map;
int **memo;
int dfs(int sr, int sc, int n)
{
    int cnt = 0;
    if (memo[sr][sc] != -1)
    {
        return memo[sr][sc];
    }
    else
    {

        for (int i = 0; i < 4; i++)
        {
            int nextr = sr + mr[i];
            int nextc = sc + mc[i];
            if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < n)
            {

                if (map[nextr][nextc] > map[sr][sc])
                {
                    cnt = max(cnt, dfs(nextr, nextc, n));
                }
            }
        }
    }

    return memo[sr][sc] = cnt + 1;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    map = new int *[n];
    memo = new int *[n];
    for (int i = 0; i < n; i++)
    {
        memo[i] = new int[n];
        map[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
            memo[i][j] = -1;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            memo[i][j] = dfs(i, j, n);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, memo[i][j]);
        }
    }

    printf("%d", ans);
    for (int i = 0; i < n; i++)
    {
        delete[] map[i];
        delete[] memo[i];
    }

    delete[] map;
    delete[] memo;
    return 0;
}
