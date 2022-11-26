#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
/*
void sol(int curSum, vector<int> coins, int K, int &answer, int curI)
{
    if (curSum == K)
    {
        ++answer;
        return;
    }
    else
    {
        if (curSum > K)
        {
            return;
        }
        for (int i = curI; i < coins.size(); i++)
        {
            sol(curSum + coins[i], coins, K, answer, i);
        }
    }
    return;
}

*/
// 코인 개수 별로 DP를 돌려준다 
void sol(int K, vector<int> coins, vector<int> cases, int &answer)
{
    cases[0] = 1;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= K; j++)
        {
            cases[j] = cases[j] + cases[j - coins[i]];
        }
    }

    answer = cases[K];
    return;
}

int main(void)
{
    int n, K;
    vector<int> coins;
    vector<int> cases(10001, 0);
    scanf("%d %d", &n, &K);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp <= K)
        {
            coins.push_back(temp);
        }
    }

    int answer = 0;

    sol(K, coins, cases, answer);
    printf("%d", answer);

    return 0;
}
