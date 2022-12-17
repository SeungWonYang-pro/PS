#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
    }

    int **perm = new int *[2001];
    for (int i = 0; i < 2001; i++)
    {
        perm[i] = new int[i + 1];
    }
    perm[0][0] = 1;
    perm[1][0] = 1;
    perm[1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
            {
                perm[i][j] = 1;
            }
            else
            {
                perm[i][j] = (((perm[i - 1][j]) % 1000000007) + (perm[i - 1][j - 1] % 1000000007)) % 1000000007;
            }
        }
    }
    int ans = perm[n][k] % 1000000007;
    for (int i = 0; i < k - 1; i++)
    {
        ans = (ans * 2) % 1000000007;
    }

    printf("%d", ans);
    for (int i = 0; i < 2001; i++)
    {
        delete[] perm[i];
    }
    delete[] perm;

    return 0;
}
