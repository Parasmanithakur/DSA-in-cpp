//Kosaraju sharir 1979
// algo for SCC -Strongly connected component
//In a Directed graph
// Approach 2 DFS -1st on adj 2nd on transpose
//all SCC forms a condensation graph viz DAG,DAG has atleast 1 node with degree 0;
#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001], tnp[1001];
bool vist[1001];
vector<int> order, scc;

void dfs(int node)
{
    vist[node] = true;
    for (int child : adj[node])
    {
        if (!vist[child])
            dfs(child);
    }
    order.push_back(node); //this will help us to keep order of out timeing and than for working with transpose
}
void dfsT(int node)
{
    vist[node] = true;
    for (int child : tnp[node])
    {
        if (!vist[child])
            dfsT(child);
    }
    scc.push_back(node);
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            adj[i].clear(), vist[i] = false;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            tnp[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (vist[i] != true)
                dfs(i);
        }
        for (int i = 1; i <= n; i++)
            vist[i] = false;
        int counter = 0;

        for (int i = 1; i <= n; i++)
        {

            if (vist[order[n - i]] != true)
            {

                scc.clear();
                dfsT(order[n - i]);
                counter++;
                for (int node : scc)
                {
                    cout << node << " ";
                    // scc
                }
                cout << endl;
            }
        }
        cout << counter; // number of scc
    }
}