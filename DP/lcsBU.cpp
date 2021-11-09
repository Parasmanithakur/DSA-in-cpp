//lCS bottom up approach

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001];

int lcs(int x, int y, string s, string t)
{
    for (int i = 0; i < x + 1; i++)
        for (int j = 0; j < y + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < x + 1; i++)
        for (int j = 1; j < y + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[x][y];
}

int main()
{
    int x, y;
    cin >> x >> y; // Take size of both the strings as input
    string s1, s2;
    cin >> s1 >> s2; // Take both the string as input

    cout << lcs(x, y, s1, s2) << endl;

    return 0;
}