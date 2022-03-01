// https://cses.fi/problemset/task/2189
// poiny location test

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

struct point
{
    ll x, y;
};
int orientation(point a, point b, point c)
{
    ll org = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
    if (org == 0)
        return 0;
    else if (org > 0)
        return 1;
    else
        return -1;
}

void solve()
{
    vector<point> points(3);
    for (int i = 0; i < 3; i++)
    {
        ll x, y;
        cin >> x >> y;
        points[i].x = x, points[i].y = y;
    }
    int org = orientation(points[0], points[1], points[2]);
    if (org == 0)
        cout << "TOUCH" << endl;
    else if (org > 0)
        cout << "RIGHT" << endl;
    else
        cout << "LEFT" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {

        solve();
    }
    return 0;
}
