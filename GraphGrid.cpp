#include<iostream>
#include<vector>
using namespace std;
bool visited[1001][1001];
int N;
 char  arr[100][100];
bool isvalid(int x,int y)
{


    if(x<0 || y<0 ||x>=N||y>=N)
      return false;
    if(visited[x][y]==true)
       return false;  
     if(arr[x][y]=='#')
       return false;  
      return true; 
}
void dfs(int x,int y)
{
    visited[x][y]=true;
    cout<<x<<" "<<y<<endl;
    if(isvalid(x-1,y))
      dfs(x-1,y);
   if(isvalid(x,y-1))
      dfs(x,y-1);
    if(isvalid(x+1,y))
      dfs(x+1,y); 
    if(isvalid(x,y+1))
      dfs(x,y+1);   
       
}
int main()
{
   
    cin>>N;
   
      for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
          cin>>arr[i][j];
    dfs(0,0);
      for(int i=0;i<N;i++)
       {
           for(int j=0;j<N;j++)
                cout<<visited[i][j]<<" ";
            cout<<endl;
       }  
       if(visited[N-1][N-1]==true)
         cout<<"can reach"  ;


    return 0;
    

}
