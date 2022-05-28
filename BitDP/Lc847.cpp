//847. Shortest Path Visiting All Nodes
//dfs +memo+ bitmasking
class Solution {
public:
   int dp[1<<13][13];//mask*node
   int dfs(int node,int mask,vector<vector<int>>&graph)
   {
       if(dp[mask][node]!=-1)//memo
            return dp[mask][node];
       if(__builtin_popcount(mask)==1)//only 1 node remaining 
           return 0;
       dp[mask][node]=INT32_MAX-1;
       for(int v:graph[node])
       {
           if((1<<v)&mask)
           {
              int ans1=dfs(v,mask,graph);
               int ans2=dfs(v,mask^(1<<node),graph);
               dp[mask][node]=min(dp[mask][node],1+min(ans1,ans2));
           }
       }
       return dp[mask][node];
   }
   int shortestPathLength(vector<vector<int>>& graph) {
       int n=graph.size();
       int mask=(1<<n)-1;
       
       memset(dp,-1,sizeof(dp));
       int res=INT_MAX;
       for(int i=0;i<n;i++)
       {
           res=min(res,dfs(i,mask,graph));//i->starting node
       }
       return res;
       
       
   }
};
