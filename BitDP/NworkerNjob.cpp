
/*
Let there be N workers and N jobs. Any worker can be assigned to perform any job,
 incurring some cost that may vary depending on the work-job assignment.
 It is required to perform all jobs by assigning exactly one worker to each job and exactly one job
  to each agent in such a way that the total cost of the assignment is minimized.

ip 4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
op 13
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <climits>
#include <cstring>

#define mod 1000000007
#define inf INT_MAX;
#define minf INT_MIN
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debarr(arr)     \
    for (auto &i : arr) \
    cout << i

const int N = 1e5 + 10;
typedef long long ll;
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
using namespace std;

ll arr[22][22];
ll dp[21][1 << 21];
ll solve1(int i, int mask, int n)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][mask] != -1)
    {
        return dp[i][mask];
    }
    ll ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {

        if ((1 << j) & mask)
        {
            ans = min(ans, arr[j][i] + solve1(i + 1, mask ^ (1 << j), n));
        }
    }
    return dp[i][mask] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    memset(dp, -1, sizeof(dp));
    ll mask = (1 << n) - 1;
    cout << solve1(0, mask, n);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        //  cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
    return 0;
}
