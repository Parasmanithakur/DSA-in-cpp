// basics of DP
//Knapsac 0 1 with memoization
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T[9][9];


int Knapsack(int W,int w[],int v[],int n)
{
    if(W==0||n==0)
      {
          return 0;
      }
    if(T[W][n]!=-1)
    {
        return T[W][n];
    }  
    else if (w[n-1]<=W)
    {
        return T[W][n]=max(v[n-1]+Knapsack(W-w[n-1],w,v,n-1),Knapsack(W,w,v,n-1));

    }  
    else if(w[n-1]>W)
        return T[W][n]= Knapsack(W,w,v,n-1);
        
}
int main()
{
    for(int i=0;i<9;i++)
     {
         for(int j=0;j<9;j++)
            T[i][j]=-1;
            
     }
    int N=8;
    int W[8]={1,2,3,4,5,6,7,8};
    int v[8]={1,2,3,4,5,6,7,8};
    cout<<Knapsack(10,W,v,8);
     for(int i=0;i<9;i++)
     {
         for(int j=0;j<9;j++)
           cout<< T[i][j]<<" ";
        cout<<endl  ;  
     }
    

    return 0;
}

