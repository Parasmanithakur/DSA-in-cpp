//application of dfs on Tree
//size of sub tree in o(n)

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10001];
void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool vist[10001];
int sub[10001]; // stores subsize of tree at that node

int dfs(int node)
{
    vist[node] = 1;
    int cur_size = 1;
    for (int child : adj[node])
    {
        if (vist[child] == 0)
        {
            cur_size += dfs(child);
        }
    }
    sub[node] = cur_size;
    return cur_size;
}

/*

        1
       2   
    3     4
   7     5 6         
*/
int main()
{
    addEdge(1, 2);
    addEdge(3, 2);
    addEdge(3, 7);
    addEdge(4, 2);
    addEdge(4, 5);
    addEdge(4, 6);
    dfs(1);
    for (int i = 0; i < 7; i++)
    {
        cout << i << " " << sub[i] << endl;
    }
    cout << endl;
}
