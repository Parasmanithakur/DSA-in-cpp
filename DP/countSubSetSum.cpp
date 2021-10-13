//Count subset with given sum
//count all subset with sum (given)
//Dp subset variation
//https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSubset(int n, int arr[], int sum)
{
    // code here
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                dp[i][j] = true;
            if (i == 0)
                dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                //in subset we use to take || (or ) here we are adding
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

// { Driver Code Starts.
int main()
{

    int N, sum;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> sum;

    cout << countSubset(N, arr, sum) << endl;

    return 0;
}
/*sample i/p
6 10
2 3 5 6 8 10
o/p
3*/