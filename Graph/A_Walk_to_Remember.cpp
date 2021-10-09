//https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/
//walk to remember hacker earth
//kosarajus algo
//scc must be of size greater than 11
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> adj[10001], tnp[10001];
bool vist[1001];
vector<int> order, scc;

void dfs(int node)
{
    vist[node] = true;
    for (int child : adj[node])
    {
        if (vist[child] != true)
        {
            dfs(child);
        }
    }
    order.push_back(node);
}
void dfs1(int node)
{
    vist[node] = true;
    for (int child : tnp[node])
    {
        if (vist[child] != true)
            dfs1(child);
    }
    scc.push_back(node);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        tnp[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vist[i] != true)
            dfs(i);
    }
    for (int i = 1; i <= n; i++)
        vist[i] = false;

    reverse(order.begin(), order.end());
    vector<bool> ans(n + 1, 0);
    for (int i : order)
    {
        if (vist[i] != true)
        {
            scc.clear();
            dfs1(i);
            if (scc.size() > 1)
                for (int node : scc)
                {
                    ans[node] = true;
                    // scc
                }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
/*
5 5
1 2
2 3
3 4
4 5
4 2
o/p
0 1 1 1 0
*/