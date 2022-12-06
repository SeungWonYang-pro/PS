#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

int map[20][20];

void sol(int a, int b, int &ans, int cnt, int curr, int curc, vector<pair<int, int>> moves,  vector<bool> &check)
{
    ++cnt;
    ans = max(ans, cnt);
    
    check[map[curr][curc]] = true;
    for (int i = 0; i < moves.size(); i++)
    {
        int nextr = curr + moves[i].first;
        int nextc = curc + moves[i].second;
        if (nextr >= 0 && nextr < a && nextc >= 0 && nextc < b)
        {
            if (check[map[nextr][nextc]] == false)
            {
                sol(a, b, ans, cnt, nextr, nextc, moves,  check);
            }
        }
    }
    check[map[curr][curc]] = false;
    cnt--;
    return;
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    vector<bool> check(26, false);
    for (int i = 0; i < a; i++)
    {
        getchar();
        for (int j = 0; j < b; j++)
        {
            char c;
            scanf("%c", &c);
            map[i][j] = c - 'A';
        }
    }
    int ans = 0;
    int cnt = 0;
    int flag = 0;
    vector<pair<int, int>> moves;
    moves.emplace_back(1, 0);
    moves.emplace_back(-1, 0);
    moves.emplace_back(0, 1);
    moves.emplace_back(0, -1);
    sol(a, b, ans, cnt, 0, 0, moves,  check);
    printf("%d", ans);
    return 0;
}
