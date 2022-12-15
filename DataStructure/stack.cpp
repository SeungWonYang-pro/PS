#include <iostream>
#include <stack>
#include <cstdio>
#include <utility>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    int *nums = new int[n];
    int *NGE = new int[n];
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        NGE[i] = -1;
        if (!st.empty())
        {
            while (st.top().second < nums[i])
            {
                NGE[st.top().first] = nums[i];
                st.pop();
                if (st.empty() == true)
                {
                    break;
                }
            }
        }
        st.push(make_pair(i, nums[i]));
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", NGE[i]);
    }

    delete[] nums;

    return 0;
}
