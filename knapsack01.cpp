//knapsac 01
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Knapsack(int W,int w[],int v[],int n)
{
    if(W==0||n==0)
      {
          return 0;
      }
    else if (w[n-1]<=W)
    {
        return max(v[n-1]+Knapsack(W-w[n-1],w,v,n-1),Knapsack(W,w,v,n-1));

    }  
    else if(w[n-1]>W)
        return Knapsack(W,w,v,n-1);
        
}
int main()
{
    int N=8;
    int W[8]={1,2,3,4,5,6,7,8};
    int v[8]={1,2,3,4,5,6,7,8};
    cout<<Knapsack(10,W,v,8);
    return 0;
}

