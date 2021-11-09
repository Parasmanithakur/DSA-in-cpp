
//https://leetcode.com/problems/shortest-common-supersequence/
//lCS bottom up approach
//printing shortest common supersequnce.
//lc1092
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
string lcs1(int x, int y, string s, string t)
{
    lcs(x, y, s, t);
    string ans;
    int i = x, j = y;
    while (i > 0 && j > 0)
    {

        if (s[i - 1] == t[j - 1])
        {
            ans.push_back(s[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans.push_back(s[i - 1]);
                i--;
            }
            else
            {
                ans.push_back(t[j - 1]);
                j--;
            }
        }
    }
    while (i > 0)
    {
        ans.push_back(s[i - 1]);
        i--;
    }
    while (j > 0)
    {
        ans.push_back(t[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{
    int x, y;
    cin >> x >> y; // Take size of both the strings as input
    string s1, s2;
    cin >> s1 >> s2; // Take both the string as input

    cout << lcs1(x, y, s1, s2) << endl;

    return 0;
}
/*5 6
acbcf
abcdaf 
op-acbcdaf 
*/