#include <iostream>
#include <cstdio>

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
    int *numbers = new int[n];
    int *firstdp = new int[n];
    int *minf = new int[n + 1];
    int *minl = new int[n + 1];
    int *lastdp = new int[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    firstdp[0] = 1;
    minf[0] = 0;
    minf[1] = numbers[0];
    int maxf = 1;
    for (int i = 1; i < n; i++)
    {
        if (numbers[i] > minf[maxf])
        {
            maxf++;
            minf[maxf] = numbers[i];
            firstdp[i] = maxf;
        }
        else
        {
            int pos = findplace(minf, numbers[i], maxf);

            if (minf[pos] > numbers[i])
            {
                minf[pos] = numbers[i];
            }
            firstdp[i] = pos;
        }
    }

    lastdp[n - 1] = 1;
    minl[0] = 0;
    minl[1] = numbers[n - 1];
    int maxl = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (numbers[i] > minl[maxl])
        {
            maxl++;
            minl[maxl] = numbers[i];
            lastdp[i] = maxl;
        }
        else
        {
            int pos = findplace(minl, numbers[i], maxl);

            if (minl[pos] > numbers[i])
            {
                minl[pos] = numbers[i];
            }
            lastdp[i] = pos;
        }
    }

    int summax = -1;
    for (int i = 0; i < n; i++)
    {
        int sum = firstdp[i] + lastdp[i] - 1;
        if (sum > summax)
        {
            summax = sum;
        }
    }
    printf("%d", summax);
    delete[] firstdp;
    delete[] lastdp;
    delete[] minf;
    delete[] minl;
    delete[] numbers;
    return 0;
}
