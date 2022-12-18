#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, c;
    scanf("%d %d", &n, &c);
    vector<int> houses;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        houses.push_back(temp);
    }
    sort(houses.begin(), houses.end(), less<int>());
    int st = 1;                                     // 최소거리
    int ed = houses[houses.size() - 1] - houses[0]; // 최대거리
    int ans;
    int k = 1; // 첫 집
    long long dis = 0;
    int mid;
    if (c == 2)
    {
        ans = houses[houses.size() - 1] - houses[0];
    }
    else
    {
        while (st <= ed)
        {

            mid = (st + ed) / 2;

            for (int i = 1; i < n; i++)
            {
                long long curdis = dis + (houses[i] - houses[i - 1]);
                if (curdis >= mid)
                {
                    k++;
                    dis = 0;
                }
                else
                {
                    dis = curdis;
                }
            }

            if (k >= c)
            {
                st = mid + 1;
                k = 1;
                dis = 0;
            }
            else if (k < c)
            {
                ed = mid - 1;
                k = 1;
                dis = 0;
            }
        }
        ans = st - 1;
    }

    printf("%d", ans);
    return 0;
}
