#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main(void)
{
    vector<pair<int, int>> move;
    move.push_back(make_pair(1, 2));
    move.push_back(make_pair(1, -2));
    move.push_back(make_pair(-1, 2));
    move.push_back(make_pair(-1, -2));
    move.push_back(make_pair(2, 1));
    move.push_back(make_pair(2, -1));
    move.push_back(make_pair(-2, 1));
    move.push_back(make_pair(-2, -1));
    
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int l;
        pair<int, int> a, b;
        scanf("%d", &l);
        scanf("%d %d", &a.first, &a.second);
        scanf("%d %d", &b.first, &b.second);
        int **check = new int*[301];
        int **min = new int*[301];
        queue<pair<int, int>> qu;
        for(int j=0; j<l; j++)
        {
            check[j] = new int[l];
            min[j] = new int [l];
        }
        for (int j = 0; j < l; j++)
        {
            for (int k = 0; k < l; k++)
            {
                check[j][k] = 0;
                min[j][k] = -1;
            }
        }
        check[a.first][a.second] = 1;
        min[a.first][a.second] = 0;
        qu.push(a);
        while (!qu.empty())
        {
            int currow = qu.front().first;
            int curcol = qu.front().second;
            if (currow == b.first && curcol == b.second)
            {
                break;
            }

            qu.pop();
            for (int j = 0; j < move.size(); j++)
            {
                if (((currow + move[j].first) < l && (currow + move[j].first) >= 0) && ((curcol + move[j].second) < l && (curcol + move[j].second) >= 0))
                {
                    
                    if (check[currow + move[j].first][curcol + move[j].second] == 0)
                    {
                        check[currow + move[j].first][curcol + move[j].second] = 1;
                        min[currow + move[j].first][curcol + move[j].second] = min[currow][curcol] + 1;
                        qu.push(make_pair(currow + move[j].first, curcol + move[j].second));
                    }
                }
            }
        }
        
        printf("%d\n",min[b.first][b.second]);
        for(int j=0; j<l; j++)
        {
            delete[]check[j];
            delete[]min[j];
        }
        delete[] check;
        delete[] min;
    }

    return 0;
}
