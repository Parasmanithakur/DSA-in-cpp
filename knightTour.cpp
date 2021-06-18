
#include<iostream>
#include<vector>
#define N 8
using namespace std;
int cntr=0;

int isSafe(int x,int y,int sol[N][N])
  {

      if(x<0 ||y<0 ||x>=N||y>=N || sol[x][y]!=-1)
       return false;
       return true;
  }

void printSol(int sol[][N])

{
    for(int i=0;i<N;i++)
     {for(int j=0;j<N;j++)
      {
          cout<<" "<<sol[i][j]<<" ";
      }
      cout<<endl;
     }

 
}
int solveKTut(int x,int y, int movei,int sol[N][N],int xMove[],int yMove[])
{
    int nextX,nextY,i;

    if(movei==N*N)
      return 1;
    for(i=0;i<8;i++)
     {
         nextX=x+xMove[i];
         nextY=y+yMove[i];
         if(isSafe(nextX,nextY,sol))
          {
              sol[nextX][nextY]=movei;
              if(solveKTut(nextX,nextY,movei+1,sol,xMove,yMove)==1)
               return 1;
               else 
                sol[nextX][nextY]=-1;
                 cntr+=1;
          }

     }   return 0;

}
void solveKT()
{
    int  sol[N][N];
    for( int i=0;i<N;i++)
      for(int j=0;j<N;j++)
         sol[i][j]=-1;

    int yMove[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
    int xMove[8]={ 1, 2, 2, 1, -1, -2, -2, -1 } ;
    sol[0][0]=0;
    if (solveKTut(0,0,1,sol,xMove,yMove)==0)
     {
         cout<<"No ans";
     }
     else 
       printSol(sol);

     




}

int main()
{

   solveKT();
   cout<<cntr;
   return 0;

}