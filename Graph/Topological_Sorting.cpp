//SPOJ toposort question

//kahns algo fot topological sorting
//variation of dfs with in arraay
//works for DAG -Directed acyclic graph6

//this variation just req lexiographical ans so just use pq (min heap) insted of simple queue
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
vector<ll>
    adj[1000001];
void addEdge(ll u, ll v)
{
    adj[u].push_back(v); // only directed graph
                         //  adj[v].push_back(u);
}
vector<ll> res;

ll in[1000001];
bool kahns(ll n)
{
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (ll i = 1; i <= n; i++)
    {
        if (in[i] == 0) // all with 0s will br pushed first
            q.push(i);
    }
    while (!q.empty())
    {
        int curr = q.top();
        res.push_back(curr);
        q.pop();
        for (ll node : adj[curr])
        {
            in[node]--;
            if (in[node] == 0)
            {
                q.push(node);
            }
        }
    }

    return (res.size() == n);
}
int main()
{

    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        addEdge(x, y);
        in[y]++;
    }
    if (!kahns(n))
        cout << "Sandro fails.";
    else
    {
        for (ll i : res)
        {
            cout << i << " ";
        }
    }
}
/*
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6
ans-1 4 3 5 7 8 2 6
2 2
1 2
2 1
ans-Sandro fails.
*/