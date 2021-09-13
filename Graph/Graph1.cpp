//Graph using stls
#include<iostream>
#include<vector>
#include<queue>

//unweighted and undirected graph 
using namespace std;
void  addEdge(vector<int> adj[],int u ,int v )
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[],int V) // printing data;
{

    for(int i=0;i<V;i++)
    {

        cout<<"Adjaceny list of vertex "<<i;
        for(auto cur:adj[i])
         {
             cout<<"->"<<cur;
         }
         cout<<endl;
    }
}
void DFSUtil(int u,vector<int> adj[],vector<bool>&visted) //recursive function for dfs
{
    visted[u]=true;
    cout<<u<<" ";
    for(int i=0;i<adj[u].size();i++)
     {
         if(visted[adj[u][i]]==false)
          DFSUtil(adj[u][i],adj,visted);
     }

}
void DFS(vector<int> adj[], int V)//function for calling DFSutil again and again
{
    vector<bool> visted(V,false);
    for(int u=0;u<V;u++)
    {
        if(visted[u]==false)
        {
            DFSUtil(u,adj,visted);
        }
    }
}

void BFS(vector<int> adj[] ,int V) //bfs 
{
    vector<bool> v(V,false); //boolean vector for checking visted nodes
    for (int i = 0; i < V; i++) {
        if (!v[i])
           {

              queue<int> q;
              q.push(i);
              v[i]=true;
              while(!q.empty())
              {
                  int f=q.front();
                  q.pop();
                  cout<<f<<" ";
                  for (auto i=adj[f].begin();i!=adj[f].end();i++)
                  {
                      if(!v[*i])
                      {
                          q.push(*i);
                          v[*i]=true;       
                      }
                  }
              }
           } 
    }
  
}

int main()
{ 
     int V;
   // cout<<"Enter Total No, vertex";
    V=5;
    vector<int> adj[5];
    
    addEdge(adj, 4, 0);
    addEdge(adj, 1, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    cout<<"DFS -";
    DFS(adj,V);
    cout<<endl<<"BFS -";
    BFS(adj,V);
    return 0;



}
