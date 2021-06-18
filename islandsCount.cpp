// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Question solved from gfg no of islands
//dfs is used in grid to find connected 1 s in all 8 directions



class Solution
{
    public:
    //Function to find the number of islands.
    bool visited[1001][1001];
   
    
    bool isvalid(int x,int y,int N,int M,vector<vector<char>>&arr)
{


    if(x<0 || y<0 ||x>=N||y>=M)
      return false;
    if(visited[x][y]==true)
       return false;  
     if(arr[x][y]=='0')
       return false;  
      return true; 
}
int dx[8]={-1,0,1,0,1,-1,1,-1};
int dy[8]={0,-1,0,1,1,-1,-1,1};
void dfs(int x,int y,int N,int M,vector<vector<char>> &arr)
{
    visited[x][y]=true;
    
    for(int i=0;i<8;i++)
     if(isvalid(x+dx[i],y+dy[i],N,M,arr))
        dfs(x+dx[i],y+dy[i],N,M,arr);
   
               
    
   
       
}
    int numIslands(vector<vector<char>>& arr) 
    {
        // Code here
       
         for(int i=0;i<1001;i++)
     for(int j=0;j<1001;j++)
       visited[i][j]=false;
        int N=arr.size();
        int M=arr[0].size();
         int cntr=0;
         for (int i=0;i<N;i++)
         {   for(int j=0;j<M;j++)      
                { 
                 if (arr[i][j] =='1' && visited[i][j]==false)
                   { 
                          dfs(i,j,N,M,arr);
                          cntr++;
                   }

                 }
         }
        
      return cntr;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
