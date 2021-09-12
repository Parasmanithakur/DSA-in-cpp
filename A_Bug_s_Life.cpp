#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
vector<int> adj[2001];
int visted[2001];
int col[2001];

void addEdge(int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

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
    ll t;
    cin >> t;
    int k = 0;
    while (t--)
    {
        ll bugs, inter;
        k++;
        cin >> bugs >> inter;
        for (int i = 1; i <= bugs; i++)
            adj[i].clear(), visted[i] = 0, col[0] = 0;
        for (int i = 1; i <= inter; i++)
        {

            ll u, v;
            cin >> u >> v;
            addEdge(u, v);
        }

        int flag = 0;
        for (int i = 1; i <= bugs; i++)
        {
            if (visted[i] == 0)
            {
                bool res = dfs(i, 1);
                if (res == false)
                {
                    flag = 1;
                }
            }
        }
        cout << " Scenario #" << k << ":" << endl;
        if (flag == 1)
        {

            cout << "Suspicious bugs found!";
        }
        else
        {
            cout << "No suspicious bugs found!";
        }
    }
    return 0;
}