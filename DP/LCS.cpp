#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b;

 
    vector<vector<int>> lcs(a.length()+1, vector<int>(b.length()+1, 0));

    for (int i = 1; i < a.length()+1; i++)
    {
        for (int j = 1; j < b.length()+1; j++)
        {
            if (a[i-1] == b[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1] + 1;  //같으면
            }
            else
            {
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);// 다르면 a 문장 i -1  까지 길이와 b 문장 j까지 길이의 최대 혹은 a 문장 i 길이 b 문장 j-1
            }
        }
    }

    

    printf("%d",lcs[a.size()][b.size()]);

    return 0;
}
