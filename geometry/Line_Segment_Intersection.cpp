
// https://cses.fi/problemset/task/2190
// cses line segment intersection
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
int orientation(Point p1, Point p2, Point p3)
{
    ll val = (p2.y - p1.y) * (p3.x - p2.x) -
             (p2.x - p1.x) * (p3.y - p2.y);

    if (val == 0)
        return 0;

    return (val > 0) ? 1 : 2;
}

bool validProjection(int a, int b, int c, int d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool doIntersect(Point a, Point b, Point c, Point d)
{
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && o4 == 0)
    {
        if (validProjection(a.x, b.x, c.x, d.x) && validProjection(a.y, b.y, c.y, d.y))
            return true;
    }

    return false;
}
void solve()
{
    vector<Point> points(4);
    for (int i = 0; i < 4; i++)
    {
        ll x, y;
        cin >> x >> y;
        points[i].x = x, points[i].y = y;
    }
    if (doIntersect(points[0], points[1], points[2], points[3]))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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
