// { Driver Code
//https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1#
// Minimum Deletions
//Given a string .delete the minimum number of characters from the string so string is a palindrome.
//similar to minimum insert.

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

// } Driver Code Ends
//User function template for C++

int dp[1001][1001];
int minimumNumberOfDeletions(string s)
{
    // code here
    string t = s;
    reverse(s.begin(), s.end());
    int n = s.length();
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    //if(n==dp[n][n])
    return n - dp[n][n];
}

int main()
{

    string S;
    cin >> S;
    cout << minimumNumberOfDeletions(S) << endl;

    return 0;
}
/*ip aebcbda
 op=2
 */