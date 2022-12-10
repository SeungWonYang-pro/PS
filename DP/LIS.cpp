#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int findplace(int *Kmin, int num, int maxK)
{
    int left = 0;
    int right = maxK;
    int mid;
    int pos;
    while (1)
    {
        if (left > right)
        {
            pos = left;
            break;
        }

        mid = (left + right) / 2;
        if (Kmin[mid] < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return pos;
}
int main(void)
{
    int n;
    scanf("%d", &n);

    int *numbers = new int[1000000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int *dp = new int[1000000];   // 특정 값을 끝값으로 갖는 최대 증가 리스트 길이
    int *Kmin = new int[1000001]; // 특정 길이를 갖는 리스트의 최소 숫자

    dp[0] = 1;
    Kmin[0] = 0;
    Kmin[1] = numbers[0];
    int maxK = 1;
    for (int i = 1; i < n; i++)
    {
        if (Kmin[maxK] < numbers[i])
        {
            maxK++;
            Kmin[maxK] = numbers[i];
        }
        else
        {
            int length = findplace(Kmin, numbers[i], maxK);

            if (Kmin[length] > numbers[i])
            {
                Kmin[length] = numbers[i];
            }
        }
    }

    
    printf("%d", maxK);
    delete[] dp;
    delete[] numbers;

    return 0;
}
