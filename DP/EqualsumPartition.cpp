//Equal sum partition
//dp -knapsack varition
//break a array in 2 set with equal sum
// similar to subset sum
//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include <iostream>
#include <vector>

using namespace std;
bool dp[1001][1001];
//if sum is sum(arr) than do subset(arr,sum/2).
bool equalsubset(vector<int> arr, int sum)
{
    int n = arr.size();

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum / 2 + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum / 2 + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum / 2];
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % 2 == 1) //if total sum is odd we cant make equal partision
        cout << 0;
    else
        cout << equalsubset(arr, sum);
}
/*sample ip 4
1 5 11 5
o/p -1*/