#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main(void)
{
    int row, col, r;
    int onerow;
    scanf("%d %d %d", &col, &onerow, &r);
    row = onerow * r;
    vector<vector<int>> tomatoes(row, vector<int>(col, 0));
    queue<pair<int, int>> qu;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &tomatoes[i][j]);
            if (tomatoes[i][j] == 1)
            {
                qu.push(make_pair(i, j));
            }
        }
    }

    vector<pair<int, int>> moves;
    moves.push_back(make_pair(1, 0));
    moves.push_back(make_pair(0, 1));
    moves.push_back(make_pair(-1, 0));
    moves.push_back(make_pair(0, -1));
    moves.push_back(make_pair(onerow, 0));
    moves.push_back(make_pair((-1) * onerow, 0));

    while (!qu.empty())
    {
        pair<int, int> cur = qu.front();
        qu.pop();
        int check = 0;
        for (int i = 0; i < moves.size(); i++)
        {
            int newrow = cur.first + moves[i].first;
            int newcol = cur.second + moves[i].second;
            if( i == 0 || i == 2)
            {
                int curf = (cur.first) / onerow;
                int nextf = newrow / onerow;
                if(curf != nextf)
                {
                    continue;
                }
            }


            if (newrow < row && newrow >= 0 && newcol < col && newcol >= 0)
            {
                if (tomatoes[newrow][newcol] == 0)
                {
                    tomatoes[newrow][newcol] = tomatoes[cur.first][cur.second] + 1;
                    qu.push(make_pair(newrow, newcol));
                }
            }
        }
    }

    

    int max = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (tomatoes[i][j] == 0)
            {
                max = -1;
                break;
            }
            else if (max < tomatoes[i][j])
            {
                max = tomatoes[i][j];
            }
        }
        if (max == -1)
        {
            break;
        }
    }
    if (max == -1)
    {
        printf("%d\n", max);
    }
    else
    {
        max = max - 1;
        printf("%d\n", max);
    }

    return 0;
}
