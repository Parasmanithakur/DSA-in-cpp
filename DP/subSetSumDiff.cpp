//minimum subset sum diff
//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
//minimize differnece between 2 subset
//Dp varition of subset
//find range ->0-sum
//find Range/2-2*j where j is first point where subset sum is valid
//Hard on gfg
#include <iostream>
#include <vector>

using namespace std;
bool subset(int sum, vector<int> arr)
{
    bool dp[1001][1001];
    int n = arr.size();
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int minSubdiff(vector<int> arr)
{
    int n = arr.size();
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];
    for (int j = range / 2; j >= 0; j--)
    {
        if (subset(j, arr) == true)
            return range - 2 * j;
    }
    return range;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minSubdiff(arr);
}
/* sample ip
  1 6 11 5
  op 1*/