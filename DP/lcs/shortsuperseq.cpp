// { Driver Code Starts
//Initial template for C++
//https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
//length of shortest common supersequence.
//lcs variation
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// } Driver Code Ends
//User function template for C++

//Function to find length of shortest common supersequence of two strings.
int dp[1001][1001];
int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    //code here

    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    return m + n - dp[m][n];
}

// { Driver Code Starts.

int main()
{

    string X, Y;
    //taking String X and Y
    cin >> X >> Y;

    //calling function shortestCommonSupersequence()

    cout << shortestCommonSupersequence(X, Y, X.size(), Y.size()) << endl;

    return 0;
}
/*ip
  abcd
xycd
op=6 */

// } Driver Code Ends