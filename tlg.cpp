#include<iostream>

using namespace std;

int solve()
{int sum(0);
   int d[1001][1001];
      while(1)
   {
     int x1,x2,y1,y2;
     cin>>x1>>y1>>x1>>y1;
     
     for(int i=x1;i<x2;i++)
     {
       sum+=d[i][y1];


     }
     for(int i=y1;i<y2;i++)
     {
       sum+=d[x2][i];
       

     }
     cout<<sum<<endl;
    }
    return sum;
}

   
int main()
{
    // int T;
    // cin>>T;
     int temp(0);
     int h=1;
     int d[1001][1001];
      for(int i=0;i<1000;i++)
          {
              h+=i;
              d[0][i]=h;
          }
           cout<<d[0][0];
     for(int i=1;i<1000;i++)
       {   h=d[0][i]; 
           for(int j=0;j<1000;j++)
           
           { d[i][j]=h+(j+1)*i ;
           }
       }
    
     return 0;
}
