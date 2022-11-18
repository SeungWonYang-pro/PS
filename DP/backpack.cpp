#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return (a.first < b.first);
}

int main(void)
{
    vector<pair<int, int>> worth;
    int N, K;
    scanf("%d %d", &N, &K);
    vector<vector<int>> table(N + 1, vector<int>(K+1, 0));
    for (int i = 0; i < N; i++)
    {
        pair<int, int> temp;
        scanf("%d %d", &temp.first, &temp.second);
        worth.push_back(temp);
    }
    sort(worth.begin(), worth.end(), compare);
    
    // 각 아이템 개수 I 총 무게 W            I개의 아이템 총 무게 W                I-1개의 아이템 W 무게 (I번째 무게가 총W보다 클 시 )
    //  아니면 비교한다 I-1개의 아이템 W-현재의 무게의 값에다 현재의 돌의 가치와 I-1개의 돌과 W 무게의 가치값과 비교한다.
    for (int i = 0; i < K+1; i++)
    {
        table[0][i] = 0;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < K+1; j++)
        {
            if ( j < worth[i - 1].first)
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {
                table[i][j] = max(table[i - 1][j - worth[i - 1].first] + worth[i - 1].second, table[i - 1][j]);
            }
        }
    }

    printf("%d",table[N][K]);

    return 0;
}
