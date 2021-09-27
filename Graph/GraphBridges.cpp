// algo to find bridges in graph
// Bridges - all those edges which when removed will increase the number of cc ,basicly break a commponent
// Approach DFS in and low theory with dfs tree concenpt

#include <iostream>
#include <algorithm>
#include <vector>
#define Maxn 10000
using namespace std;

vector<int> adj[Maxn];
void addEgde(int u, int v)
{

    adj[u].push_back(v);
    adj[v].push_back(u);
}
int timer = 0;
int vist[Maxn], in[Maxn], low[Maxn];
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
        }
        else
        { //fwd edge
            dfs(child, node);
            if (low[child] > in[node])
                cout << node << " -" << child << " is bridge" << endl;
            low[node] = min(low[node], low[child]);
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear(), vist[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        addEgde(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vist[i] == 0)
            dfs(i);
    }
}
