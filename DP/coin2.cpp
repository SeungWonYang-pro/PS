#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> coins;
    vector<int> mincoin(10001, 0);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        coins.push_back(temp);

        if (temp < 10001)
        {
            mincoin[temp] = 1;
        }
    }
    mincoin[0] = 1;
    sort(coins.begin(), coins.end());
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= k; j++)
        {
            int temp;
            if (mincoin[j - coins[i]] != 0)
            {
                temp = mincoin[j - coins[i]] + 1;

                if (mincoin[j] != 0)
                {
                    if (mincoin[j] > temp)
                    {
                        mincoin[j] = temp;
                    }
                }
                else
                {
                    mincoin[j] = temp;
                }
            }
        }
    }

    if (mincoin[k] == 0)
    {
        mincoin[k] = -1;
    }

    printf("%d", mincoin[k]);
    
    return 0;
}
