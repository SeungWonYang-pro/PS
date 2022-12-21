#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
int **map;

int mr[4] = {-1, 0, 1, 0};
int mc[4] = {0, -1, 0, 1};

typedef struct n
{
    int x, y;
    int cost;
} node;

int bfs(int n, int &br, int &bc, int bShark)
{
    bool **check = new bool *[n];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        check[i] = new bool[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            check[i][j] = false;
        }
    }

    queue<node> q;
    check[br][bc] = true;
    node temp;
    temp.x = br;
    temp.y = bc;
    temp.cost = 0;
    q.push(temp);
    int curr = -1;
    int curc = -1;
    while (!q.empty())
    {
        node cur = q.front();
        if (res != 0)
        {
            if (res < cur.cost)
            {
                br = curr;
                bc = curc;
                map[br][bc] = 0;
                break;
            }
        }
        if (map[cur.x][cur.y] > 0 && map[cur.x][cur.y] < bShark)
        {
            if (curr == -1 && curc == -1)
            {
                curr = cur.x;
                curc = cur.y;
                res = cur.cost;
            }
            else
            {
                if (curr > cur.x)
                {
                    curr = cur.x;
                    curc = cur.y;
                }
                else
                {
                    if (curr == cur.x)
                    {
                        if (curc > cur.y)
                        {
                            curc = cur.y;
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int nextr = cur.x + mr[i];
                int nextc = cur.y + mc[i];

                if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < n)
                {
                    if (check[nextr][nextc] == false)
                    {
                        check[nextr][nextc] = true;
                        if (map[nextr][nextc] <= bShark)
                        {
                            node newNode;
                            newNode.x = nextr;
                            newNode.y = nextc;
                            newNode.cost = cur.cost + 1;
                            q.push(newNode);
                        }
                    }
                }
            }
        }

        q.pop();
    }

    if (q.empty() == true && curr != -1 && curc != -1)
    {
        br = curr;
        bc = curc;
        map[br][bc] = 0;
    }

    if (curr == -1 && curc == -1)
    {
        br = curr;
        bc = curc;
        res = 0;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] check[i];
    }

    delete check;

    return res;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    map = new int *[n];

    int *food = new int[7];
    int br, bc;
    for (int i = 0; i < 7; i++)
    {
        food[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] != 0 && map[i][j] != 9)
            {
                food[map[i][j]]++;
            }
            else if (map[i][j] == 9)
            {
                br = i;
                bc = j;
                map[i][j] = 0;
            }
        }
    }

    int bShark = 2;

    int curPosF = food[1];
    int to;
    int ans = 0;

    if (curPosF < 2) // 크기 2에서 끝
    {

        for (int i = 0; i < curPosF; i++)
        {
            ans = ans + bfs(n, br, bc, bShark);
            if (br == -1 && bc == -1)
            {
                break;
            }
        }
    }
    else
    {
        if (curPosF >= 2) // 크기 3이상
        {
            curPosF = curPosF + food[2];

            if (curPosF >= 5) // 크기 4이상
            {
                curPosF = curPosF + food[3];
                if (curPosF >= 9) // 크기 5이상
                {
                    curPosF = curPosF + food[4];
                    if (curPosF >= 14) // 크기 6이상
                    {
                        curPosF = curPosF + food[5];
                        if (curPosF >= 20) // 크기 7 이상
                        {
                            curPosF = curPosF + food[6];
                            int cnt = 0;
                            for (int i = 0; i < curPosF; i++)
                            {
                                ans = ans + bfs(n, br, bc, bShark);
                                cnt++;
                                if (cnt == 2)
                                {
                                    bShark++;
                                }
                                else if (cnt == 5)
                                {
                                    bShark++;
                                }
                                else if (cnt == 9)
                                {
                                    bShark++;
                                }
                                else if (cnt == 14)
                                {
                                    bShark++;
                                }
                                else if (cnt == 20)
                                {
                                    bShark++;
                                }

                                if (br == -1 && bc == -1)
                                {
                                    break;
                                }
                            }
                        }
                        else // 크기 6에서 끝
                        {
                            int cnt = 0;
                            for (int i = 0; i < curPosF; i++)
                            {
                                ans = ans + bfs(n, br, bc, bShark);
                                cnt++;
                                if (cnt == 2)
                                {
                                    bShark++;
                                }
                                else if (cnt == 5)
                                {
                                    bShark++;
                                }
                                else if (cnt == 9)
                                {
                                    bShark++;
                                }
                                else if (cnt == 14)
                                {
                                    bShark++;
                                }
                                if (br == -1 && bc == -1)
                                {
                                    break;
                                }
                            }
                        }
                    }
                    else // 크기 5에서 끝
                    {
                        int cnt = 0;
                        for (int i = 0; i < curPosF; i++)
                        {
                            ans = ans + bfs(n, br, bc, bShark);
                            cnt++;
                            if (cnt == 2)
                            {
                                bShark++;
                            }
                            else if (cnt == 5)
                            {
                                bShark++;
                            }
                            else if (cnt == 9)
                            {
                                bShark++;
                            }
                            if (br == -1 && bc == -1)
                            {
                                break;
                            }
                        }
                    }
                }
                else // 크기가 4에서 끝
                {
                    int cnt = 0;
                    for (int i = 0; i < curPosF; i++)
                    {
                        ans = ans + bfs(n, br, bc, bShark);
                        cnt++;
                        if (cnt == 2)
                        {
                            bShark++;
                        }
                        else if (cnt == 5)
                        {
                            bShark++;
                        }
                        if (br == -1 && bc == -1)
                        {
                            break;
                        }
                    }
                }
            }
            else // 크기 3에서 끝
            {
                int cnt = 0;
                for (int i = 0; i < curPosF; i++)
                {
                    ans = ans + bfs(n, br, bc, bShark);
                    cnt++;
                    if (cnt == 2)
                    {
                        bShark++;
                    }
                    if (br == -1 && bc == -1)
                    {
                        break;
                    }
                }
            }
        }
    }

    printf("%d", ans);
    for (int i = 0; i < n; i++)
    {
        delete[] map[i];
    }
    delete[] map;
    delete[] food;
    return 0;
}
