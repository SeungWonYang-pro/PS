#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void sol(int n, int m, int sr, int sc, int to, vector<vector<int>> &map, int &ans, int &flag)
{
    if (flag == 1)
    {
        return;
    }
    if (map[sr][sc] == 0)
    {
        map[sr][sc] = 2;
        ++ans;
    }

    if (to == 0) // 북
    {
        if ((sc - 1) >= 0)
        {
            if (map[sr][sc - 1] == 0) //  서 쪽
            {
                int newto = 3;
                sol(n, m, sr, sc - 1, newto, map, ans, flag);
            }
            else
            {
                if (sr + 1 < n) // 남쪽
                {
                    if (map[sr + 1][sc] == 0)
                    {
                        int newto = 2;
                        sol(n, m, sr + 1, sc, newto, map, ans, flag);
                    }
                    else
                    {
                        if (sc + 1 < m) // 동쪽
                        {
                            if (map[sr][sc + 1] == 0)
                            {
                                int newto = 1;
                                sol(n, m, sr, sc + 1, newto, map, ans, flag);
                            }
                            else
                            {
                                if ((sr - 1) >= 0)
                                {
                                    if (map[sr - 1][sc] == 0)
                                    {
                                        int newto = 0;
                                        sol(n, m, sr - 1, sc, newto, map, ans, flag);
                                    }
                                    else
                                    {
                                        if (sr + 1 < n)
                                        {
                                            if (map[sr + 1][sc] == 2)
                                            {
                                                sol(n, m, sr + 1, sc, to, map, ans, flag);
                                            }
                                            else if (map[sr + 1][sc] == 1)
                                            {
                                                flag = 1;
                                            }
                                        }
                                        else
                                        {
                                            flag = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (to == 1) //동
    {

        if ((sr - 1) >= 0) // 북쪽
        {
            if (map[sr - 1][sc] == 0)
            {
                int newto = 0;
                sol(n, m, sr - 1, sc, newto, map, ans, flag);
            }
            else
            {
                if ((sc - 1) >= 0)
                {
                    if (map[sr][sc - 1] == 0) //  서 쪽
                    {
                        int newto = 3;
                        sol(n, m, sr, sc - 1, newto, map, ans, flag);
                    }
                    else
                    {
                        if (sr + 1 < n) // 남쪽
                        {
                            if (map[sr + 1][sc] == 0)
                            {
                                int newto = 2;
                                sol(n, m, sr + 1, sc, newto, map, ans, flag);
                            }
                            else
                            {
                                if (sc + 1 < m) // 동쪽
                                {
                                    if (map[sr][sc + 1] == 0)
                                    {
                                        int newto = 1;
                                        sol(n, m, sr, sc + 1, newto, map, ans, flag);
                                    }
                                    else
                                    {
                                        if (sc - 1 >= 0)
                                        {
                                            if (map[sr][sc - 1] == 2)
                                            {
                                                sol(n, m, sr, sc - 1, to, map, ans, flag);
                                            }
                                            else if (map[sr][sc - 1] == 1)
                                            {
                                                flag = 1;
                                            }
                                        }
                                        else
                                        {
                                            flag = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (to == 2) // 남
    {
        if (sc + 1 < m) // 동쪽
        {
            if (map[sr][sc + 1] == 0)
            {
                int newto = 1;
                sol(n, m, sr, sc + 1, newto, map, ans, flag);
            }
            else
            {
                if ((sr - 1) >= 0) //             북
                {
                    if (map[sr - 1][sc] == 0)
                    {
                        int newto = 0;
                        sol(n, m, sr - 1, sc, newto, map, ans, flag);
                    }
                    else
                    {
                        if ((sc - 1) >= 0)
                        {
                            if (map[sr][sc - 1] == 0) //  서 쪽
                            {
                                int newto = 3;
                                sol(n, m, sr, sc - 1, newto, map, ans, flag);
                            }
                            else
                            {
                                if (sr + 1 < n) // 남쪽
                                {
                                    if (map[sr + 1][sc] == 0)
                                    {
                                        int newto = 2;
                                        sol(n, m, sr + 1, sc, newto, map, ans, flag);
                                    }
                                    else
                                    {
                                        if (sr - 1 >= 0)
                                        {
                                            if (map[sr - 1][sc] == 2)
                                            {
                                                sol(n, m, sr - 1, sc, to, map, ans, flag);
                                            }
                                            else if (map[sr - 1][sc] == 1)
                                            {
                                                flag = 1;
                                            }
                                        }
                                        else
                                        {
                                            flag = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (to == 3) //서
    {
        if (sr + 1 < n) // 남쪽
        {
            if (map[sr + 1][sc] == 0)
            {
                int newto = 2;
                sol(n, m, sr + 1, sc, newto, map, ans, flag);
            }
            else
            {
                if (sc + 1 < m) // 동쪽
                {
                    if (map[sr][sc + 1] == 0)
                    {
                        int newto = 1;
                        sol(n, m, sr, sc + 1, newto, map, ans, flag);
                    }
                    else
                    {
                        if ((sr - 1) >= 0) //             북
                        {
                            if (map[sr - 1][sc] == 0)
                            {
                                int newto = 0;
                                sol(n, m, sr - 1, sc, newto, map, ans, flag);
                            }
                            else
                            {
                                if ((sc - 1) >= 0)
                                {
                                    if (map[sr][sc - 1] == 0) //  서 쪽
                                    {
                                        int newto = 3;
                                        sol(n, m, sr, sc - 1, newto, map, ans, flag);
                                    }
                                    else
                                    {
                                        if (sc + 1 < m)
                                        {
                                            if (map[sr][sc + 1] == 2)
                                            {
                                                sol(n, m, sr, sc + 1, to, map, ans, flag);
                                            }
                                            else if (map[sr][sc + 1] == 1)
                                            {
                                                flag = 1;
                                            }
                                        }
                                        else
                                        {
                                            flag = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return;
}

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);
    vector<vector<int>> map(n, vector<int>(m, 0));
    int sr, sc, to;
    scanf("%d %d %d", &sr, &sc, &to);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
    int flag = 0;
    int answer = 0;
    sol(n, m, sr, sc, to, map, answer, flag);

    printf("%d\n", answer);
    return 0;
}
