#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct n
{
    int x, y;
    int num;
} node;

bool compare(node a, node b)
{
    return a.num > b.num;
}

void sol(int n, int m, int map[500][500], int &ans)
{
    for (int i = 0; i < n; i++) // 가로 4
    {
        for (int j = 0; j <= m - 4; j++)
        {
            int temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
            if (temp > ans)
            {
                ans = temp;
            }
        }
    }
    for (int i = 0; i < m; i++) // 세로 4
    {
        for (int j = 0; j <= n - 4; j++)
        {
            int temp = map[j][i] + map[j + 1][i] + map[j + 2][i] + map[j + 3][i];
            if (temp > ans)
            {
                ans = temp;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) // 가로 2 세로 2
    {
        for (int j = 0; j < m - 1; j++)
        {
            int temp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
            if (temp > ans)
            {
                ans = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            int temp;
            if (i == 0) // 가로 3 세로 1
            {
                temp = map[i][j] + map[i][j + 1] + map[i][j + 2];
                temp = temp + max(max(map[i + 1][j], map[i + 1][j + 1]), map[i + 1][j + 2]);
            }
            else if (i == n - 1)
            {
                temp = temp = map[i][j] + map[i][j + 1] + map[i][j + 2];
                temp = temp + max(max(map[i - 1][j], map[i - 1][j + 1]), map[i - 1][j + 2]);
            }
            else
            {
                temp = temp = map[i][j] + map[i][j + 1] + map[i][j + 2];
                temp = temp + max(max(max(map[i - 1][j], map[i - 1][j + 1]), map[i - 1][j + 2]), max(max(map[i + 1][j], map[i + 1][j + 1]), map[i + 1][j + 2]));
            }
            if (temp > ans)
            {
                ans = temp;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 2; j++)
        {
            int temp;
            if (i == 0) // 세로 3 가로 1
            {
                temp = map[j][i] + map[j + 1][i] + map[j + 2][i];
                temp = temp + max(max(map[j][i + 1], map[j + 1][i + 1]), map[j + 2][i + 1]);
            }
            else if (i == m - 1)
            {
                temp = temp = map[j][i] + map[j + 1][i] + map[j + 2][i];
                temp = temp + max(max(map[j][i - 1], map[j + 1][i - 1]), map[j + 2][i - 1]);
            }
            else
            {
                temp = map[j][i] + map[j + 1][i] + map[j + 2][i];
                temp = temp + max(max(max(map[j][i + 1], map[j + 1][i + 1]), map[j + 2][i + 1]), max(max(map[j][i - 1], map[j + 1][i - 1]), map[j + 2][i - 1]));
            }
            if (temp > ans)
            {
                ans = temp;
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++) // 엇갈린 가로2 세로 2
        {
            int temp;
            if (j == 0)
            {
                temp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
            }
            else if (j == m - 2)
            {
                temp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j - 1];
            }
            else
            {
                temp = map[i][j] + map[i][j + 1] + max((map[i + 1][j + 1] + map[i + 1][j + 2]), (map[i + 1][j] + map[i + 1][j - 1]));
            }
            if (temp > ans)
            {
                ans = temp;
            }
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++) // 엇갈린 가로2 세로 2
        {
            int temp;
            if (j == 0)
            {
                temp = map[j][i] + map[j + 1][i] + map[j + 1][i + 1] + map[j + 2][i + 1];
            }
            else if (j == n - 2)
            {
                temp = map[j][i] + map[j + 1][i] + map[j][i + 1] + map[j - 1][i + 1];
            }
            else
            {
                temp = map[j][i] + map[j + 1][i] + max((map[j + 1][i + 1] + map[j + 2][i + 1]), (map[j][i + 1] + map[j - 1][i + 1]));
            }
            if (temp > ans)
            {
                ans = temp;
            }
        }
    }
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<node> v;
    int map[500][500];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &(map[i][j]));
        }
    }

    int ans = 0;
    sol(n, m, map, ans);
    printf("%d", ans);

    return 0;
}
