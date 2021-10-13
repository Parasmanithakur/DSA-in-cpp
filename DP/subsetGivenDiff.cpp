//count number of subset with a given difference
//divide array in 2 subset such that abs(s1-s2)=given diff
//dp varition of subset
// Approach
//s1+s2=s
//s1-s2=d
//s1=(s+d)/2
//becomes subsetsum(arr,sum).
#include <iostream>
#include <vector>

using namespace std;
int dp[1001][1001];
int subsetsum(vector<int> arr, int sum)
{
    int n = arr.size();

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 1)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int countSubsetGivenDiff(vector<int> arr, int diff)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if ((sum + diff) % 2 != 0) // check for floating number
        return 0;
    int sum1 = (sum + diff) / 2;
    return subsetsum(arr, sum1);
}
int main()
{

    int n, diff;
    cin >> n >> diff;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countSubsetGivenDiff(arr, diff);
}
/*i/p
4 1
 1 1 2 3
 o/p
3*/