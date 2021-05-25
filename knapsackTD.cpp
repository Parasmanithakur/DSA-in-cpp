// basics of DP
//Knapsac 0 1 with Top down approach.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T[9][9];// table of n+1,w+1


int main()
{
    int n,w;
    int W[8]={1,2,3,4,5,6,7,8};
    int v[8]={2,2,3,4,5,6,7,8};
    n=w=8;
    for(int i=0;i<9;i++)// init of Table T  the base condition in recursive method
     {  for(int j=0;j<9;j++)
        if (i==0||j==0)
          T[i][j]=0;
     }    
   for(int i =1;i<n+1;i++) // Real works
     {
         for(int j=1;j<w+1;j++)
         {
             if(W[i-1]<=j)
             {
                 T[i][j]=max(v[i-1]+   T[i-1][j-W[i-1]],   T[i-1][j]);
             }
             else 
                T[i][j]=T[i-1][j];

         }
     }       
      cout<<T[8][8]<<endl;// ans is stored at last row and last col

     
    int N=8;
   
  //  printing topdown table
      for(int i=0;i<9;i++)
     {  for(int j=0;j<9;j++)
        
         cout<< T[i][j]<<" ";
         cout<<endl;
     }   
    

    return 0;
}

