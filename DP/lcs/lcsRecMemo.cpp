//lcs memo+recursion
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[1001][1001];
int lcslength(string &s, string &t, int sL, int tL)
{
    if (sL == 0 || tL == 0)
        return 0;
    if (dp[sL - 1][tL - 1] != -1)
        return dp[sL - 1][tL - 1];

    if (s[sL - 1] != t[tL - 1])
    {
        return dp[sL - 1][tL - 1] = max(lcslength(s, t, sL - 1, tL), lcslength(s, t, sL, tL - 1));
    }
    else
        return dp[sL - 1][tL - 1] = 1 + lcslength(s, t, sL - 1, tL - 1);
}

int main()
{

    string s, t;
    cin >> s;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    cout
        << lcslength(s, t, s.length(), t.length());
    return 0;
}
/*
 i/p=ABCDGH
AEDFHR
o/p= 3*/