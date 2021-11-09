// { Driver Code Starts
//Initial template for C++
//https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1#
// /Form a palindrome
//Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
//lcs variations
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

// } Driver Code Ends
//User function template for C++

int dp[1001][1001];
int countMin(string str)
{
    //complete the function ]
    int n = str.size();
    string s = str;
    reverse(s.begin(), s.end());
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (str[i - 1] == s[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return n - dp[n][n];
}

// { Driver Code Starts.
int main()
{

    string str;
    cin >> str;
    cout << countMin(str) << endl;

    return 0;
}
/* 
ip-abcda
op-2 
*/