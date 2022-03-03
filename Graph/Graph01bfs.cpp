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
#include <deque>
#include <cstring>

#define INF INT_MAX
#define minf INT_MIN
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debarr(arr)     \
    for (auto &i : arr) \
    cout << i           \
         << " "
#define mod 1000000007
typedef long long ll;

using namespace std;
vector<pair<ll, ll>> adj[100000];

void solve()
{
    ll e, v;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        adj[x].push_back({y, 0});
        adj[y].push_back({x, 1});
    }

    deque<ll> q;
    vector<ll> levl(v + 1, 100000);

    q.push_front(1);
    levl[1] = 0;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop_front();

        for (auto &it : adj[cur])
        {
            ll child = it.first;
            ll wt = it.second;

            if (levl[cur] + wt < levl[child])
            {
                levl[child] = levl[cur] + wt;
                if (wt == 1)
                    q.push_back(child);
                else
                    q.push_front(child);
            }
        }
    }
    if (levl[v] == 100000)
        cout << -1 << endl;
    else
        cout << levl[v] << endl;

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}
