#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, vector<vector<char>> pic, vector<vector<int>> &check, pair<int, int> cur)
{
    vector<pair<int, int>> move;
    move.push_back(make_pair(1, 0));
    move.push_back(make_pair(0, 1));
    move.push_back(make_pair(-1, 0));
    move.push_back(make_pair(0, -1));
    queue<pair<int, int>> q;

    check[cur.first][cur.second] = 1;
    q.push(cur);
    while (!q.empty())
    {
        int curr = q.front().first;
        int curc = q.front().second;
        q.pop();

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
                        check[newr][newc] = 1;
                        q.push(make_pair(newr, newc));
                    }
                }
            }
        }
    }

    return 1;
}



int main(void)
{
    int n;
    scanf("%d", &n);
    vector<vector<char>> pic(n, vector<char>(n, 'a'));
    vector<vector<char>> rbpic(n, vector<char>(n, 'a'));
    vector<vector<int>> check(n, vector<int>(n, 0));
    vector<vector<int>> rbcheck(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        getchar();
  
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &pic[i][j]);
            rbpic[i][j] = pic[i][j];
            if (rbpic[i][j] == 'G')
            {
                rbpic[i][j] = 'R';
            }
        }
    }
    int ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check[i][j] == 0)
            {
                ans1 = ans1 + bfs(n, pic, check, make_pair(i, j));

            }
        }
    }
    int ans2 =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rbcheck[i][j] == 0)
            {
                ans2 = ans2 + bfs(n, rbpic, rbcheck, make_pair(i, j));
            }
        }
    }

    printf("%d %d", ans1,ans2);
    return 0;
}
