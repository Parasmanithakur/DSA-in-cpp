//longest pallindrom sub seq
// lcs varation

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int lcsPallindrome(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    int n = s.length();
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

/* ip =agbcba
 op=5
*/
int main()
{
    string s;
    cin >> s;
    cout << lcsPallindrome(s);
}