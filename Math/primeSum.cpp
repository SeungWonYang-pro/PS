#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> primes;

void make_prime(int n)
{
    bool *nums = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        nums[i] = true;
    }

    nums[0] = false;
    nums[1] = false;
    for (int i = 0; i <= n; i++)
    {
        if (nums[i] == true)
        {
            for (int j = 2; i * j <= n; j++)
            {
                nums[i * j] = false;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (nums[i] == true)
        {
            primes.push_back(i);
        }
    }

    delete[] nums;
}

int main(void)
{

    int n;

    scanf("%d", &n);
    make_prime(n);
    int m = primes.size();
    int ans = 0;
    int sum;
    for (int i = 0; i < primes.size(); i++)
    {
        sum = primes[i];
        for (int j = i + 1; j < primes.size(); j++)
        {
            sum = sum + primes[j];
            if (sum >= n)
            {
                break;
            }
        }
        if (sum == n)
        {
            ans++;
        }
    }
    printf("%d", ans);

    return 0;
}
