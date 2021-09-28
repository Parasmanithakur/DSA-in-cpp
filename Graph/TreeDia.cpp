//Tree diameter is longest distance between any 2 nodes
//this approach is adv using 2dfs
//First apply dfs on random node find largest dist than apply dfs on that node
//spoj PT07Z - Longest path in a tree
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
vector<int> adj[100];
void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int dist[100];
bool visted[100];
void dfs(int node, int d)
{
    visted[node] = 1;
    dist[node] = d;
    for (int child : adj[node])
    {
        if (visted[child] == 0)
            dfs(child, d + 1);
    }
}

int main()
{
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 7);
    addEdge(2, 4);
    addEdge(6, 4);
    addEdge(5, 4);
    dfs(1, 1);
    pair<int, int> maxD = {0, 0};
    for (int i = 1; i <= 7; i++)
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
    dfs(maxD.second, 1);
    int ans = 0;
    cout << endl;
    for (int i = 1; i <= 7; i++)
    {
        ans = max(ans, dist[i]);
        // cout << i << " " << dist[i] << endl;
    }
    cout << ans;
}
