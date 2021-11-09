//length of longest common substring

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001];
int longestCommonSubstr(string s, string t, int n, int m)
{
    // your code here
    int len = 0;
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                len = max(len, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    return len;
}

// { Driver Code Starts.
/*ip
3 3
ABC
ACB 
op 1*/
int main()
{

    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubstr(s1, s2, n, m) << endl;
}
