// codeforces Bertown roads
//bridges -graph theory

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <stack>
#include <unordered_map>
#define Maxn 1000001
typedef long long ll;
using namespace std;
vector<int> adj[Maxn];

void addEgde(int u, int v)
{

    adj[u].push_back(v);
    adj[v].push_back(u);
}
int timer = 0;
int vist[Maxn], in[Maxn], low[Maxn];
bool hashBridges = 0;
vector<pair<int, int>> edgeList;
void dfs(int node, int par = -1)
{
    vist[node] = 1;
    in[node] = low[node] = timer++;
    for (int child : adj[node])
    {
        if (child == par)
            continue;
        if (vist[child] == 1)
        { // back edge . Back edge cannot be a bridge ever
            low[node] = min(low[node], in[child]);
            if (in[child] < in[node])
                edgeList.push_back({node, child});
        }
        else
        { //fwd edge
            dfs(child, node);
            if (low[child] > in[node])
            {
                // cout << node << " -" << child << " is bridge" << endl;
                hashBridges = 1;
                return;
            }
            edgeList.push_back({node, child});
            low[node] = min(low[node], low[child]);
        }
    }
}

int main()
{

    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        addEgde(x, y);
    }

    dfs(1);

    if (hashBridges == 0)
    {
        for (pair<int, int> x : edgeList)
        {
            cout << x.first << " " << x.second << endl;
        }
    }

    else
        cout << 0 << endl;
    return 0;
}