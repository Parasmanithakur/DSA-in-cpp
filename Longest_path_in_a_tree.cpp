//Tree diameter is longest distance between any 2 nodes
//this approach is adv using 2dfs
//First apply dfs on random node find largest dist than apply dfs on that node
//spoj PT07Z - Longest path in a tree
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;
vector<ll> adj[10001];
void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
ll dist[10001];
bool visted[10001];
void dfs(ll node, ll d)
{
    visted[node] = 1;
    dist[node] = d;
    for (ll child : adj[node])
    {
        if (visted[child] == 0)
            dfs(child, d + 1);
    }
}

int main()
{
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        adj[i].clear(), visted[i] = 0, dist[i] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;

        cin >> u >> v;
        addEdge(u, v);
    }
    dfs(1, 0);
    pair<ll, ll> maxD = {0, 0};
    for (ll i = 1; i <= n; i++)
    {
        if (maxD.first <= dist[i])
        {
            maxD.first = dist[i];
            maxD.second = i;
        }
        //  cout << i << " " << dist[i] << endl;
        dist[i] = 0;
        visted[i] = 0;
    }
    dfs(maxD.second, 0);
    ll ans = 0;
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
        // cout << i << " " << dist[i] << endl;
    }
    cout << ans << endl;
}