#include <bits/stdc++.h>

using namespace std;

string s;
int i;

ifstream f("evaluare.in");
ofstream g("evaluare.out");
int fact();

int termen()
{
    int r = fact();
    while (s[i] == '*' || s[i] == '/')
    {
        if (s[i] == '*')
        {
            i++;
            r *= fact();
        }
        else
        {
            i++;
            r /= fact();
        }
    }
    return r;
}
int expr()
{
    int r = termen();
    while (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '+')
        {
            i++;
            r += termen();
        }
        else
        {
            i++;
            r -= termen();
        }
    }
    return r;
}

int fact()
{
    int r = 0;
    if (s[i] == '(')
    {
        i++;
        r = expr();
        i++;
    }
    else
    {
        while (s[i] >= '0' && s[i] <= '9')
        {
            r = r * 10 + (s[i] - '0');
            i++;
        }
    }
    return r;
}

int main()
{
    f >> s;
    g << expr();
    return 0;
}