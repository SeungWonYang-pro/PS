#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

void prime(int M, int N)
{

    bool *primes = new bool[N + 1];

    for (int i = 0; i <= N; i++)
    {
        primes[i] = true;
    }

    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i <= sqrt(N); i++)
    {
        if (primes[i])
        {

            for (int j = 2; j * i <= N; j++)
            {
                primes[i * j] = false;
            }
        }
    }
    

    for (int i = M; i <= N; i++)
    {
        if(primes[i])
        {
            printf("%d\n",i);
        }
     }
}

int main(void)
{
    int M, N;
    scanf("%d %d", &M, &N);

    prime(M, N);

    return 0;
}
