//kahns algo fot topological sorting
//variation of dfs with in arraay
//works for DAG -Directed acyclic graph6
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
void addEdge(int u, int v)
{
    adj[u].push_back(v); // only directed graph
                         //  adj[v].push_back(u);
}

int in[1001];
void kahns(int n)
{
    vector<int> res;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0) // all with 0s will br pushed first
            q.push(i);
    }
    while (!q.empty())
    {
        int curr = q.front();
        res.push_back(curr);
        q.pop();
        for (int node : adj[curr])
        {
            in[node]--;
            if (in[node] == 0)
            {
                q.push(node);
            }
        }
    }
    for (int i : res)
    {
        cout << i << " ";
    }
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
        in[y]++;
    }
    kahns(n);
}