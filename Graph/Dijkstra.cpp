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
typedef long long ll;

using namespace std;
vector<pair<int, int>> adj[100000];
ll n, m;
void dijkstra(int source)
{
    vector<int> vist(n + 1, 0);
    vector<int> dist(n + 1, 100000);
    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;
    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if (vist[v] == 1)
            continue;
        vist[v] = 1;
        for (auto child : adj[v])
        {
            int child_v = child.first;

            int wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

void solve()

{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
    }
    ll source;
    cin >> source;
    dijkstra(source);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}
