#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

bool check(int **map)
{
    bool **rowcheckmap = new bool *[9];
    bool **colcheckmap = new bool *[9];
    bool **sparsecheckmap = new bool *[9];
    for (int i = 0; i < 9; i++)
    {
        rowcheckmap[i] = new bool[10];
        colcheckmap[i] = new bool[10];
        sparsecheckmap[i] = new bool[10];
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            rowcheckmap[i][j] = false;
            colcheckmap[i][j] = false;
            sparsecheckmap[i][j] = false;
        }
        rowcheckmap[i][0] = true;
        colcheckmap[i][0] = true;
        sparsecheckmap[i][0] = true;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            rowcheckmap[i][map[i][j]] = true;
            colcheckmap[j][map[i][j]] = true;
            sparsecheckmap[3 * (i / 3) + (j / 3)][map[i][j]] = true;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (rowcheckmap[i][j] == false || colcheckmap[i][j] == false || sparsecheckmap[i][j] == false)
            {
                return false;
            }
        }
    }

    return true;
}

void printmap(int **map)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void sol(int **map, bool **rowcheckmap, bool **colcheckmap, bool **sparsechckmap, vector<pair<int, int>> zeros, bool &finish)
{

    if (finish == true)
    {
        return;
    }
    if (zeros.size() == 0)
    {
        if (check(map))
        {
            finish = true;
            printmap(map);
        }
    }
    else
    {
        int nextr = zeros[0].first;
        int nextc = zeros[0].second;

        zeros.erase(zeros.begin());
        for (int i = 1; i < 10; i++)
        {
            if (rowcheckmap[nextr][i] == false && colcheckmap[nextc][i] == false && sparsechckmap[3 * (nextr / 3) + (nextc / 3)][i] == false)
            {

                map[nextr][nextc] = i;
                rowcheckmap[nextr][i] = true;
                colcheckmap[nextc][i] = true;
                sparsechckmap[3 * (nextr / 3) + (nextc / 3)][i] = true;
                sol(map, rowcheckmap, colcheckmap, sparsechckmap, zeros, finish);
                if (finish == true)
                {
                    return;
                }
                else
                {
                    map[nextr][nextc] = 0;
                    rowcheckmap[nextr][i] = false;
                    colcheckmap[nextc][i] = false;
                    sparsechckmap[3 * (nextr / 3) + (nextc / 3)][i] = false;
                }
            }
        }
    }

    return;
}

int main(void)
{
    int **map = new int *[9];
    bool **rowcheckmap = new bool *[9];
    bool **colcheckmap = new bool *[9];
    bool **sparsecheckmap = new bool *[9];
    vector<pair<int, int>> zeros;
    bool finish = false;
    for (int i = 0; i < 9; i++)
    {
        map[i] = new int[9];
        rowcheckmap[i] = new bool[10];
        colcheckmap[i] = new bool[10];
        sparsecheckmap[i] = new bool[10];
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            rowcheckmap[i][j] = false;
            colcheckmap[i][j] = false;
            sparsecheckmap[i][j] = false;
        }
        rowcheckmap[i][0] = true;
        colcheckmap[i][0] = true;
        sparsecheckmap[i][0] = true;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0)
            {
                zeros.push_back(make_pair(i, j));
            }
            else
            {
                rowcheckmap[i][map[i][j]] = true;
                colcheckmap[j][map[i][j]] = true;
                sparsecheckmap[3 * (i / 3) + (j / 3)][map[i][j]] = true;
            }
        }
    }
    sol(map, rowcheckmap, colcheckmap, sparsecheckmap, zeros, finish);

    for (int i = 0; i < 9; i++)
    {
        delete[] map[i];
        delete[] rowcheckmap[i];
        delete[] colcheckmap[i];
        delete[] sparsecheckmap[i];
    }

    delete[] rowcheckmap, colcheckmap, sparsecheckmap;
    delete[] map;
}
