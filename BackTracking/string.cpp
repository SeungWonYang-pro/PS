#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool correct(string curstr)
{
    int cntJ = 0;
    int cntM = 0;

    for (int i = 0; i < curstr.size(); i++)
    {
        if (curstr[i] == 'a' || curstr[i] == 'e' || curstr[i] == 'i' || curstr[i] == 'o' || curstr[i] == 'u')
        {
            cntM++;
        }
        else
        {
            cntJ++;
        }
        if (cntM >= 1 && cntJ >= 2)
        {
            return true;
        }
    }

    return false;
}

void sol(int L, vector<char> chars, string curstr, int curi)
{
    if (curstr.length() == L)
    {
        if (correct(curstr))
        {
            printf("%s\n", curstr.c_str());
        }
    }
    else
    {
        if (curi < chars.size()-1)
        {
            string newone = curstr;
            sol(L, chars, curstr + chars[curi + 1], curi + 1);
            sol(L, chars, newone, curi + 1);
        }
        else{
            return;
        }
    }

    return;
}

int main(void)
{
    int L, C;
    scanf("%d %d", &L, &C);
    vector<char> chars;
    for (int i = 0; i < C; i++)
    {
        getchar();
        char c;
        scanf("%c", &c);
        chars.push_back(c);
    }

    sort(chars.begin(), chars.end());

    
    string curstr = "";
    string newone = "";
    int curi = 0;
    sol(L, chars, newone + chars[curi], curi);
    sol(L, chars, curstr, curi);


    return 0;
}
