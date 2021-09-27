//articulation point or cut vertex point
// point /vertex which when removed will increase the nuber of connnected components
//do DFS with parent ,in and low array , similar to bridge but diff
//DFS tree.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
set<int> cutP;
vector<int> adj[1001];
bool vist[1001];
int in[1001], low[1001];
int timer = 0; // timer variable to fill in and low arrays
void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(int node, int p = -1)
{
    vist[node] = 1;
    low[node] = in[node] = timer++;
    int children = 0; // find vhildren number in dfs tree
    for (int child : adj[node])
    {
        if (child == p)
            continue;
        if (vist[child] == 1)
        {
            low[node] = min(low[node], in[child]); //minimizing low of node
        }
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] >= in[node] && p != -1)
            {
                cutP.insert(node);
            }
            children++;
        }
    }
    if (p == -1 && children > 1)
        cutP.insert(node);
}
int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vist[i] == 0)
            dfs(i);
    }
    cout << "The articulation point are\n";
    for (int s : cutP)
    {
        cout << s << endl;
    }
    return 0;
}