//knapsack default dp question
//used a bottum up approach

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int knapsack(int n, int w, vector<int> val, vector<int> wt)
{
    for (int i = 0; i < n + 1; i++) //intialization of dp matrix
        for (int j = 0; j < w + 1; j++)

        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j) //check if knapsack is not full
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                //                          inclusion                   exclusion
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    return dp[n][w];
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << knapsack(n, w, val, wt);
}
/* sample
 i/p4 7
1 4 5 7
1 3 4 5
o/p 9*/