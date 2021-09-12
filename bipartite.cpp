#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100];

void addEdge(int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}
bool visted[100];
int col[100];
bool dfs(int node, int color)
{
    visted[node] = 1;
    col[node] = color;
    for (int child : adj[node])
    {
        if (visted[child] == 0)
        {
            if (dfs(child, color ^ 1) == false)
                return false;
        }
        if (col[node] == col[child])
            return false;
    }
    return true;
}
int main()

{
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(3, 4);
    addEdge(4, 2);
    cout << dfs(1, 1);
}
Scenario #1 : Suspicious bugs found !Scenario #2 : No suspicious bugs found !Scenario #1 : Suspicious bugs found !Scenario #2 : No suspicious bugs found !