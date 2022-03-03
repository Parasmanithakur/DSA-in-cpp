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

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> adj[n + 1];
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back({y, 0});
        adj[y].push_back({x, 0});
    }
    vector<ll> dis(n + 1, 1e5 + 10);
    dis[1] = 0;
    deque<ll> q;
    q.push_back(1);
    for (int i = 1; i < n; i++)
    {
        adj[i + 1].push_back({i, 1});
        adj[i].push_back({i + 1, 1});
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (auto edge : adj[v])
        {
            int u = edge.first;
            int w = edge.second;
            if (dis[v] + w < dis[u])
            {
                dis[u] = dis[v] + w;
                if (w == 1)
                {
                    q.push_back(u);
                }
                else
                {
                    q.push_front(u);
                }
            }
        }
    }
    cout << dis[n] << endl;
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
