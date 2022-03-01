// https://cses.fi/problemset/task/2191
// CSES Problem Set
// Polygon Area
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

#define inf INT_MAX;
#define minf INT_MIN
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debarr(arr)     \
    for (auto &i : arr) \
    cout << i           \
         << " "
#define mod 1000000007

const int N = 1e5 + 10;
typedef long long ll;
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
using namespace std;
struct Point
{
    ll x, y;
};
void solve()
{
    ll n;
    cin >> n;
    vector<Point> points(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        points[i].x = x, points[i].y = y;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i + 1;
        if (i == n)
        {
            j = 1;
        }
        ans += (points[i].y + points[j].y) * (points[i].x - points[j].x);
    }
    cout << abs(ans) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    {

        solve();
    }
    return 0;
}
