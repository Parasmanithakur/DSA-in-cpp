// { Driver Code
//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#
//lcs varaition
//repeating subseq longest
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// } Driver Code Endslass Solution
int dp[1001][1001];
int LongestRepeatingSubsequence(string str)
{
    // Code here
    int n = str.length();
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (str[i - 1] == str[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    return dp[n][n];
}

// { Driver Code Starts.
int main()
{

    string str;
    cin >> str;

    int ans = LongestRepeatingSubsequence(str);
    cout << ans << "\n";
    return 0;
}
/*ip =axxxy
 op =2 */