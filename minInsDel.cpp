//Minimum number of deletions and insertions
// { Driver Code Startshttps://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1#

//Given two strings str1 and str2.transform str1 to str2 minimum insert/del
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int lcs(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[n][m];
}

int minOperations(string str1, string str2)
{
    // Your code goes here
    int x = lcs(str1, str2);
    return str1.length() + str2.length() - 2 * x;
}

// { Driver Code Starts.
int main()
{

    string s1, s2;
    cin >> s1 >> s2;

    cout << minOperations(s1, s2) << "\n";

    return 0;
}
/* ip
  heap pea
   op 3 */
// } Driver Code Ends