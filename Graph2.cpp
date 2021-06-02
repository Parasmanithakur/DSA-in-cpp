#include<iostream>
#include<vector>
#include<map>
#include<list> 
#include<queue>


using namespace std;

class Graph
{

    void DFSUtil(int v);
    public:
     map<int,list <int>> adj;
     map<int,bool> visited;
     void addEdge (int v,int w);
     void DFS();
     void DFS(int );
     void unvist(); //to unvist a node after a dfs
     void BFS();

};
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);


}
void Graph::DFSUtil(int v)
{
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++)
     {
         if(!visited[*it])
           {
               DFSUtil(*it);
           }
     }
}
void Graph::DFS()
{
    for (auto i:adj)
    {
        if(visited[i.first]==false)
        {
            DFSUtil(i.first);
        }
          
    }

}
void Graph::DFS(int v)
{
    
    visited[v] = true;
    cout << v << " ";
 
    
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
void Graph::unvist()
{
      for (auto i:adj)
    {
      visited[i.first]=false;
    }
}
void Graph::BFS()
{
    for (auto i:adj) 
    {
        if (!visited[i.first])
           {

              queue<int> q;
              q.push(i.first);
              visited[i.first]=true;
              while(!q.empty())
              {
                  int f=q.front();
                  q.pop();
                  cout<<f<<" ";
                  for (auto i=adj[f].begin();i!=adj[f].end();i++)
                  {
                      if(!visited[*i])
                      {
                          q.push(*i);
                          visited[*i]=true;       
                      }
                  }
              }
           }
    }
}
int main()
{
    Graph g;
   g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
    g.addEdge(5,6); 
    cout<<"DFS is ";
    g.DFS();
    g.unvist();
    cout<<endl;
    cout<<"DFS from 0: ";
    g.DFS(0);
    
    g.unvist();
    cout<<endl;
    cout<<"BFS ";
    g.BFS();
}
