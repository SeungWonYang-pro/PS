#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <utility>

using namespace std;

typedef struct n
{
    int x, y;
    int cnt;
    int skill;

} node;
int **map;
void printmap(vector<vector<bool>> map, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void sol(int n, int m, int &ans, vector<vector<bool>> check)
{
    queue<node> q;
    check[0][0] = true; // 벽 부수는 기술 있을 때
    node temp;
    temp.x = 0;
    temp.y = 0;
    temp.cnt = 1;
    temp.skill = 1;
    vector<vector<bool>> checkOne(n, vector<bool>(m, false)); // 벽 부수는 기술 없을 때
    q.push(temp);
    checkOne[0][0] = true;
    int mr[4] = {1, -1, 0, 0};
    int mc[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        node cur = q.front();
        if (cur.x == n - 1 && cur.y == m - 1)
        {
            ans = cur.cnt;
            break;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int nextr = cur.x + mr[i];
                int nextc = cur.y + mc[i];
                if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < m)
                {
                    if (cur.skill == 1)
                    {
                        if (check[nextr][nextc] == false)
                        {
                            check[nextr][nextc] = true;
                            if (map[nextr][nextc] == 0)
                            {
                                node newNode;
                                newNode.x = nextr;
                                newNode.y = nextc;
                                newNode.cnt = cur.cnt + 1;
                                newNode.skill = 1;
                                q.push(newNode);
                            }
                            else if (map[nextr][nextc] == 1)
                            {
                                checkOne[nextr][nextc] = true;
                                node newNode;
                                newNode.x = nextr;
                                newNode.y = nextc;
                                newNode.cnt = cur.cnt + 1;
                                newNode.skill = 0;
                                q.push(newNode);
                            }
                        }
                    }
                    else
                    {

                        if (checkOne[nextr][nextc] == false)
                        {
                            checkOne[nextr][nextc] = true;
                            if (map[nextr][nextc] == 0)
                            {
                                node newNode;
                                newNode.x = nextr;
                                newNode.y = nextc;
                                newNode.cnt = cur.cnt + 1;
                                newNode.skill = 0;
                                q.push(newNode);
                            }
                        }
                    }
                }
            }
        }

        q.pop();
    }
    return;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    string a;
    map = new int *[n];
    vector<vector<bool>> check(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = a[j] - '0';
        }
    }
    int ans = -2;
    sol(n, m, ans, check);
    if (ans == -2)
    {
        ans = -1;
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
    {
        delete[] map[i];
    }
    delete[] map;
    return 0;
}
