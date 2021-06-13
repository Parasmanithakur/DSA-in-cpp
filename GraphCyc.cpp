// cycle dectation in graph using dfs


#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int>adj[],int u,int v) //std graph add function
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool DFSUtil(int u, vector<bool> visited,int parent,vector<int>adj[])
{   // a recurive function
    visited[u]=true;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end(); it++)
     {
         if(!visited[*it])
          { if(DFSUtil(*it,visited,u,adj))
            {  
                 return true;
            }
          }
        else if(*it!=parent)
           return true;     
     }
     return false;
}
bool DFS (vector<int> adj[],int v)
{
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
     {
         if(!visited[i])
           {
               if(DFSUtil(i,visited,-1,adj))
                 return true ;
           }
           
     }
     return false;
}

int main()
{
       int V;
   // cout<<"Enter Total No, vertex";
    V=5;
    vector<int> adj[3];
    
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    
    //addEdge(adj, 2, 3);
   // addEdge(adj, 3, 4);
   cout<<"Does it has a cyle"<<endl  ;
   if ( DFS(adj,3) )
    cout<<"Yes"<<endl  ;
    else 
      cout<<"No";   
    return 0;
}