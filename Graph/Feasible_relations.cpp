// Feasible relations question from hacker earth
//Graph theory
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> adj[1000001];
int vist[1000001], cc[1000001]; // maintain a cc array for each connected component

/*   1-2-3
       /  \      this one connected component ,whose cc will be 1
      4   5   
      now  6-7-8 is another  connected component whose each cc wiil be 2
      just check cc array and findout if != nodes lie in same or antoher connected component 
   */
int curc = 0; // mainting curc c number to pass in dfs

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(int node)
{
    vist[node] = 1;
    cc[node] = curc;
    for (int i : adj[node])
    {
        if (vist[i] != 1)
            dfs(i);
    }
    return;
}

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        curc = 0;
        vector<pair<int, int>> p;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vist[i] = 0;
        }
        for (int i = 0; i < k; i++)
        {
            int u, v;
            string s;
            cin >> u >> s >> v;
            if (s == "=")
            {
                addEdge(u, v); // if 1==2
            }
            else
                p.push_back({u, v}); // if 1 != 2
        }
        for (int i = 1; i <= n; i++)
        {
            if (vist[i] == 0)
            {
                curc++;
                dfs(i);
            }
        }
        bool flag = 1;
        for (int i = 0; i < p.size(); i++)
        {
            int a = p[i].first;
            int b = p[i].second;
            if (cc[a] == cc[b])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}