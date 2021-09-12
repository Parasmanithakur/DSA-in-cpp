#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1001];
int visted[1001], dist[1001];
void addEdge(int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}

void DFS(int node, int d) //function for calling DFSutil again and again
{
    visted[node] = 1;
    dist[node] = d;
    for (int u = 0; u < v[node].size(); u++)
    {
        if (visted[v[node][u]] != 1)
        {
            DFS(v[node][u], dist[node] + 1);
        }
    }
    return;
}

int main()
{
    int n = 7;

    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(5, 6);

    cout << "distane of " << 6 << " is ";
    DFS(1, 0);
    for (int i = 1; i < n; i++)

        cout << dist[i];
}