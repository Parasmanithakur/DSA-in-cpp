//cses Planet cycles que
//graph directed
//approach  DFS
// mainting a path in every dfs call
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> adj[1000001];
bool vist[1000001] = {false};
int pathlength[1000001];
queue<int> path;
int steps;
void dfs(int node)
{
    path.push(node); // as only one edge is there no need of looping
    //we are pushing in path without checking if visted - therefore we can find out if cycle is there from path

    if (vist[node] == true)
    {
        steps += pathlength[node];
        return;
    }
    vist[node] = true;
    steps++;
    dfs(adj[node][0]);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[i].push_back(x); //no need for a vector as only one edge is there
    }
    for (int i = 1; i <= n; i++)
    {
        steps = 0; // making steps 0 for every new connected component
        if (vist[i] != true)
        {
            dfs(i);
            int dec = 1;
            while (!path.empty())
            {
                int x = path.front();
                if (x == path.back()) // if front == back there for we are in a cycle
                    dec = 0;          // thus steps will be same
                pathlength[x] = steps;
                steps -= dec; //if not in cycle steps will dec
                path.pop();
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << pathlength[i] << " ";
}
/* 5
2 4 3 1 4
ans =3 3 1 3 4     

 3-3    5->4  ->   1
            ^ \   |
               2 <

  4,1,2 are in cycle therefore same transportations
  5 connects cycle but not a part of it.             
*/