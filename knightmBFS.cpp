#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int  board[8][8];

class cell
{
    public:
    int x,y,dis;
    cell(){};
   cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
 };
 bool isSafe(int x,int y)
  {
      if(x<0||x>=8 ||y<0||y>=8)
        return false;
        return true;
  }


void printBoard()
{
    for(int i=0;i<8;i++)
     {
         for(int j=0;j<8;j++)
            cout<<board[i][j]<<"  ";
            cout<<endl;
     }
     cout<<"-------------------"<<endl;


}
int dx[8]={1,1,-1,-1,2,-2,2,-2};
int dy[8]={-2,2,-2,2,1,-1,-1,1};

int bfs( int x,int y,int X,int Y)
{
    queue<cell> q;
    q.push(cell(x,y,0));
    cell C;
    board[x][y]=-1;
    printBoard();
    while(!q.empty())
    {
        C=q.front();
        q.pop();
        if ( ( C.x==X) &&( C.y==Y))
         {
                return C.dis;
         }
        for (int i = 0; i < 8; i++)
        {
            x = C.x + dx[i];
            y = C.y + dy[i];
             if (isSafe(x, y) && !board[x][y])
             {
                board[x][y] =true;
                q.push(cell(x, y, C.dis + 1));
             }
        }
    }
    return 0;

}
int soln()
{
     int x,y;
     cin>>x>>y;
      for(int i=0;i<8;i++)
   {
     for(int j=0;j<8;j++)
      {
       if(i<=1 || i>=6)
         board[i][j]=9;
       else
         board[i][j]=false; 
      }

    }
     printBoard();
    int X,Y;
    cin>>X>>Y;
     int ans=bfs(x,y,X,Y);
     printBoard();

     return ans;
}
int main()
 {
    
      for(int i=0;i<8;i++)
   {
     for(int j=0;j<8;j++)
      {
       if(i<=1 || i>=6)
         board[i][j]=9;
       else
         board[i][j]=false; 
      }

    }
    int x,y;//knight current possition
    cout<<"Enter lost knight current location"<<endl;
    cin>>x>>y;
    cout<<"Enter knightType (wr/wl/bl/br)"<<endl;
    string knightType;
    cin>>knightType;
    int X,Y;
    if(knightType[0]=='W' || knightType[0]=='w')
      {
          if(knightType[1]=='l' ||knightType[1]=='L' )
            {
                X=7;
                Y=1;
            }
            else 
              {
                  X=7;
                  Y=6;
              }
      }
      else
         {
             if(knightType[1]=='l'||knightType[1]=='L')
              {
                  X=0;
                Y=1;
              }
              else
               {
                    
                  X=0;
                  Y=6;
              
               }
         }
         board[X][Y]=false;
         printBoard();
         
         int ans=bfs(x,y,X,Y);
         cout<<endl;
         printBoard();
         cout<<ans;
   


 }