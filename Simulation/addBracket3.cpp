#include <iostream>
#include <string>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

char *expr;
vector<int> nums;
vector<int> expo;
int cal(vector<int> prior, int n)
{
    vector<int> curnum = nums;
    vector<int> curexpo = expo;
    vector<bool> curexpr(n, false);

    for (int i = 0; i < prior.size(); i++)
    {
        curexpr[prior[i]] = true;
        int temp = prior[i];
        while (curexpr[temp - 1] == true)
        {
            temp = temp - 2;
        }
        int fN = curnum[temp - 1];
        int sN = curnum[prior[i] + 1];
        int ex = curexpo[prior[i]];
        if (ex == 1)
        {
            curnum[temp - 1] = fN + sN;
            curexpr[prior[i] + 1] = true;
        }
        else if (ex == 2)
        {
            curnum[temp - 1] = fN - sN;
            curexpr[prior[i] + 1] = true;
        }
        else if (ex == 3)
        {
            curnum[temp - 1] = fN * sN;
            curexpr[prior[i] + 1] = true;
        }
    }

    

    for (int i = 1; i < n; i = i + 2)
    {
        if (curexpr[i] == false)
        {
            if (curexpo[i] == 3)
            {
                curexpr[i] = true;
                int temp = i;
                while (curexpr[temp - 1] == true)
                {
                    temp = temp - 2;
                }
                int fN = curnum[temp - 1];
                int sN = curnum[i + 1];
                curexpr[i + 1] = true;
                curnum[temp - 1] = fN * sN;
            }
        }
    }
    int sum = curnum[0];

    for (int i = 1; i < curnum.size(); i = i + 2)
    {
        if (curexpr[i] == false)
        {
            if (curexpo[i] == 1)
            {
                sum = sum + curnum[i + 1];
            }
            else if (curexpo[i] == 2)
            {
                sum = sum - curnum[i + 1];
            }
        }
    }

    return sum;
}

void sol(vector<int> prior, int cur, int n, int &ans)
{
    if (cur == n)
    {

        int temp = cal(prior, n);

        if (temp > ans)
        {
            ans = temp;
        }
    }
    else
    {

        vector<int> newPrior;
        for (int i = 1; i < n; i = i + 2)
        {
            newPrior.push_back(i);
        }
        do
        {
            sol(newPrior, n, n, ans);

        } while (
            next_permutation(newPrior.begin(), newPrior.end()));
    }

    return;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    expr = new char[n];
    nums = vector<int>(n, 0);
    expo = vector<int>(n, 0);
    scanf("%s", expr);

    for (int i = 0; i < n; i++)
    {
        if (expr[i] == '+')
        {
            expo[i] = 1;
        }
        else if (expr[i] == '-')
        {
            expo[i] = 2;
        }
        else if (expr[i] == '*')
        {
            expo[i] = 3;
        }
        else
        {
            nums[i] = expr[i] - '0';
        }
    }

    vector<int> prior;

    int ans = INT_MIN;

    sol(prior, 1, n, ans);

    printf("%d", ans);

    delete[] expr;

    return 0;
}
