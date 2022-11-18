#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{

    int T;
    scanf("%d", &T);
    map<string, int> nummap;
    for (int i = 1; i <= 100; i++)
    {
        nummap[to_string(i)] = i;
    }

    string cmd;
    while (T > 0)
    {
        cin >> cmd;
        int n;
        scanf("%d", &n);
        string snum;
        vector<int> numbers;
        cin >> snum;

        for (int i = 0; i < snum.length(); i++)
        {
            if (snum[i] >= '0' && snum[i] <= '9')
            {
                int j = i + 1;
                while (1)
                {
                    if (snum[j] >= '0' && snum[j] <= '9')
                    {
                        j++;
                    }
                    else
                    {
                        j--;
                        break;
                    }
                }
                string a = snum.substr(i, j - i + 1);
                i = j;
                numbers.push_back(nummap[a]);
            }
        }
        int cmdlength = cmd.length();
        int Rcnt = 0;
        int totalR = 0;
        int totalD = 0;
        vector<int> numofcmd;
        numofcmd.push_back(0);
        numofcmd.push_back(0);
        for (int i = 0; i < cmdlength; i++)
        {
            if (cmd[i] == 'R')
            {
                ++totalR;
                if (Rcnt == 0)
                {
                    Rcnt = 1;
                }
                else
                {
                    Rcnt = 0;
                }
            }
            else if (cmd[i] == 'D')
            {
                ++totalD;
                ++numofcmd[Rcnt];
            }
        }

        if (totalD > n)
        {
            printf("error\n");
        }
        else
        {

            if (totalR % 2 != 0)
            {
                reverse(numbers.begin(), numbers.end());
                int temp = numofcmd[0];
                numofcmd[0] = numofcmd[1];
                numofcmd[1] = temp;
            }
            if (numbers.size() == 0 || totalD == n)
            {
                printf("[]\n");
            }
            else
            {
                for (int i = numofcmd[0]; i < numbers.size() - numofcmd[1]; i++)
                {
                    if (i == numofcmd[0])
                    {
                        printf("[");
                    }
                    printf("%d", numbers[i]);
                    if (i != numbers.size() - numofcmd[1] - 1)
                    {
                        printf(",");
                    }
                    else
                    {
                        printf("]\n");
                    }
                }
            }
        }

        T--;
    }

    return 0;
}
