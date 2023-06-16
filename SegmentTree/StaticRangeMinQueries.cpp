//https://cses.fi/problemset/task/1647/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
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
 
const int N = 2e5 + 10;
typedef long long ll;
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
using namespace std;
vector<ll> seg(4 * N);
vector<ll> arr(N);
void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = arr[high];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = min(seg[2 * ind + 2], seg[2 * ind + 1]);
}
int query(int ind, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
    {
        return seg[ind];
    }
    if (low > r || high < l)
        return INT_MAX;
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return min(right, left);
}
 
void solve()
{
    ll n, q;
    cin >> n >> q;
 
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(0, 0, n - 1);
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
 
        b--, a--;
        cout << query(0, 0, n - 1, a, b) << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    solve();
    return 0;
}
