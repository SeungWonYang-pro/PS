#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void rotateC(string &a)
{
    string newS = "";
    newS += a[a.length() - 1];
    newS += a.substr(0, a.length() - 1);

    a = newS;

    return;
}

void rotateRC(string &a)
{
    string newS = "";
    newS += a.substr(1, a.length() - 1);
    newS += a[0];
    a = newS;

    return;
}

void turn(string &a, string &b, string &c, string &d, int k, int to)
{
    if (k == 1)
    {
        if (to == 1)
        {
            if (a[2] == b[6]) // a b
            {
                rotateC(a);
                return;
            }
            else // a b
            {
                if (b[2] == c[6])
                {
                    rotateC(a);
                    rotateRC(b);
                    return;
                }
                else
                {
                    if (c[2] == d[6])
                    {
                        rotateC(a);
                        rotateRC(b);
                        rotateC(c);
                        return;
                    }
                    else
                    {
                        rotateC(a);
                        rotateRC(b);
                        rotateC(c);
                        rotateRC(d);
                    }
                }
            }
        }
        else // 반시계
        {
            if (a[2] == b[6]) // a b
            {
                rotateRC(a);
                return;
            }
            else // a b
            {
                if (b[2] == c[6])
                {
                    rotateRC(a);
                    rotateC(b);
                    return;
                }
                else
                {
                    if (c[2] == d[6])
                    {
                        rotateRC(a);
                        rotateC(b);
                        rotateRC(c);
                        return;
                    }
                    else
                    {
                        rotateRC(a);
                        rotateC(b);
                        rotateRC(c);
                        rotateC(d);
                        return;
                    }
                }
            }
        }
    }
    else if (k == 2)
    {
        if (to == 1)
        {
            if (a[2] != b[6])
            {
                rotateRC(a);
            }

            if (b[2] == c[6])
            {
                rotateC(b);
                return;
            }
            else
            {
                if (c[2] == d[6])
                {
                    rotateC(b);
                    rotateRC(c);
                    return;
                }
                else
                {
                    rotateC(b);
                    rotateRC(c);
                    rotateC(d);
                    return;
                }
            }
        }
        else
        {
            if (a[2] != b[6])
            {
                rotateC(a);
            }

            if (b[2] == c[6])
            {
                rotateRC(b);
                return;
            }
            else
            {
                if (c[2] == d[6])
                {
                    rotateRC(b);
                    rotateC(c);
                    return;
                }
                else
                {
                    rotateRC(b);
                    rotateC(c);
                    rotateRC(d);
                }
            }
        }
    }
    else if (k == 3)
    {
        if (to == 1)
        {
            if (c[2] != d[6])
            {
                rotateRC(d);
            }

            if (c[6] == b[2])
            {
                rotateC(c);
                return;
            }
            else
            {
                if (b[6] == a[2])
                {
                    rotateC(c);
                    rotateRC(b);
                    return;
                }
                else
                {
                    rotateC(c);
                    rotateRC(b);
                    rotateC(a);
                }
            }
        }
        else
        {
            if (c[2] != d[6])
            {
                rotateC(d);
            }

            if (c[6] == b[2])
            {
                rotateRC(c);
                return;
            }
            else
            {
                if (b[6] == a[2])
                {
                    rotateRC(c);
                    rotateC(b);
                    return;
                }
                else
                {
                    rotateRC(c);
                    rotateC(b);
                    rotateRC(a);
                }
            }
        }
    }
    else if (k == 4)
    {
        if (to == 1)
        {
            if (d[6] == c[2]) // a b
            {
                rotateC(d);
                return;
            }
            else // a b
            {
                if (c[6] == b[2])
                {
                    rotateC(d);
                    rotateRC(c);
                    return;
                }
                else
                {
                    if (b[6] == a[2])
                    {
                        rotateC(d);
                        rotateRC(c);
                        rotateC(b);
                        return;
                    }
                    else
                    {
                        rotateC(d);
                        rotateRC(c);
                        rotateC(b);
                        rotateRC(a);
                    }
                }
            }
        }
        else // 반시계
        {
            if (d[6] == c[2]) // a b
            {
                rotateRC(d);
                return;
            }
            else // a b
            {
                if (c[6] == b[2])
                {
                    rotateRC(d);
                    rotateC(c);
                    return;
                }
                else
                {
                    if (b[6] == a[2])
                    {
                        rotateRC(d);
                        rotateC(c);
                        rotateRC(b);
                        return;
                    }
                    else
                    {
                        rotateRC(d);
                        rotateC(c);
                        rotateRC(b);
                        rotateC(a);
                    }
                }
            }
        }
    }

    return;
}

int main(void)
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k, to;
        cin >> k >> to;
        turn(a, b, c, d, k, to);
    }

    int answer = 0;
    if (a[0] == '1')
    {
        answer += 1;
    }
    if (b[0] == '1')
    {
        answer += 2;
    }
    if (c[0] == '1')
    {
        answer += 4;
    }
    if (d[0] == '1')
    {
        answer += 8;
    }

    printf("%d", answer);

    return 0;
}
