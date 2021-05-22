// May long challenge on codecheff
//https://www.codechef.com/MAY21C/problems/TCTCTOE
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

class Grid
{
public:

	char grid[3][3];
	Grid()
	{
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				 grid[i][j]='-';
			}
		}

	}

	int IsSingleWinner(int t)
	{
		int temp, owin, xwin;
		temp = owin = xwin = 0;
		for (int i = 0, j = 0;i < 3;i++)
			if(grid[i][j] =='X' || grid[i][j]=='O')
				if (grid[i][j] == grid[i][j + 1] && grid[i][j + 2] == grid[i][j + 1])
				{
					temp++;
					if (grid[i][j] == 'X')
						xwin = 1;
					else
						owin = 1;
				}
	    
		for (int i = 0, j = 0;j< 3;j++)
			if (grid[i][j] == 'X' || grid[i][j] == 'O')
		     	if (grid[i][j] == grid[i+1][j] && grid[i+1][j] == grid[i+2][j])
			{
				temp++;
				if (grid[i][j] == 'X')
					xwin = 1;
				else
					owin = 1;
			}
	//	if (temp > 1)
	//		return 0;
		if (grid[1][1] == 'X' || grid[1][1] == 'O')
		{//Diagnol check
			if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
			{
				temp++;
				if (grid[1][1] == 'X')
					xwin = 1;
				else
					owin = 1;
			}
			if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
			{
				temp++;
				if (grid[1][1] == 'X')
					xwin = 1;
				else
					owin = 1;
			
			}
				//cout <<"Temp is"<< temp;
		}
		if (temp >  1  &&owin==xwin)
			return 0;// multi winner 
		if (temp > 1 && owin != xwin)
			return 1;
		if (temp==0)
			return 2;// no winer
		if (temp == 1)
		{
			if (xwin == 1)
			{
		//		cout << "XWINS";
				return 11;// 1 winerr ie x
			}
			else if (owin == 1)
			{
		//		cout << "OWINS";
				return 10;// 1 winner ie o
			}
		}

	}
	int reachable()// tells if reachable
	{
		int Xcount, Ocount, other;
		Xcount = Ocount = other = 0;// other will tell if more moves can be played or not
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				if (grid[i][j] == 'X')
					Xcount++;
				else if (grid[i][j] == 'O')
					Ocount++;
				else
					other++;
			}
		}
		//cout << "X is " << Xcount << "Yis" << Ocount << " other " << other << endl;
		if (abs(Xcount - Ocount) > 1) // not Reachable as 1 player has more moves
			return 3;
		if (Ocount > Xcount)
			return 3;
	  
	   if (other % 2 == 0 && Ocount > Xcount)
	   {
		   return 3;
	   }
	   if (other % 2 != 0 && Ocount != Xcount)
	   {
		   return 3;
	   }

	   if (other == 0 && Ocount >4)
		   return 3;
	   if (IsSingleWinner(other) == 0)//and other > 0) //now moves are ok but mutliple winner 
		   return 3;
	   if (other > 0)// now board is not full  
		{
		  
		   if (IsSingleWinner(other) == 11  )// 1 winner ie x
			{
			   if (Xcount > Ocount)
				   return 1;// board is not full but single winner 
			   else
				   return 3;
			}
		   if (IsSingleWinner(other) == 10)// 1 winner ie O
		   {
			  // cout << "TESt";
			   if (Xcount == Ocount)
				   return 1;
			   if(Ocount!=Xcount)
				   return 3;
		   }
			if (IsSingleWinner(other) == 2)
				return 2;// not full but no winner

		}
	    if (other == 0) // board is full
		{
			if(IsSingleWinner(other) == 10 &&(Ocount != Xcount))
				return 3;
			else		
				return 1;
			
			
		}
	
	
	}
};
int main()
{

	int t;
	Grid x;
	cin >> t;
	while (t--)
	{
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				cin >> x.grid[i][j];
			}

		}
		
		cout <<x.reachable()<<endl;
		





	}

}
