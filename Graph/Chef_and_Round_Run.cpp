
//https://www.codechef.com/AUG16/problems/CHEFRRUN
// scc application
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <stack>
#include <unordered_map>

typedef long long ll;
using namespace std;
vector<ll> adj[100001], tnp[100001];
bool vist[100001];
vector<int> order, scc;
void dfs(int node)
{
    vist[node] = true;
    for (int child : adj[node])
    {
        if (!vist[child])
            dfs(child);
    }
    order.push_back(node);
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

    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            adj[i - 1].clear(), tnp[i - 1].clear(), order.clear(), vist[i - 1] = false;
        for (int i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            ll y = i - 1;
            x = (x + y + 1) % n;

            adj[y].push_back(x);
            tnp[x].push_back(y);
        }

        for (int i = 1; i <= n; i++)
        {
            if (vist[i - 1] != true)
                dfs(i - 1);
        }
        for (int i = 1; i <= n; i++)
            vist[i - 1] = false;
        int counter = 0;
        reverse(order.begin(), order.end());
        for (int i : order)
        {

            if (vist[i] != true)
            {

                scc.clear();
                dfsT(i);
                if (scc.size() == 1 && (scc[0] != adj[scc[0]][0]))
                    continue;
                counter += scc.size(); // number of nodes in scc
            }
        }
        cout << counter << endl;
    }
}
/*
input -3
4
1 1 1 1
4
3 0 0 0
4
0 0 0 2
output-
 4
1
2*/