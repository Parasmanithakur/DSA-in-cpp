
//lc 464 
// dp|bitmasking
class Solution {
public:
    int  dp[1<<21][2]; //Dp with bitmasking
    bool recur(int sum,int mask,int m,int chance=0)
    {
        if(sum<=0)
             return false;
        if(dp[mask][chance]!=-1)
            return dp[mask][chance];
        bool ans=false;
        for(int i=0;i<m;i++)
        {
            if((1<<i)&mask)
            {
                ans=ans|(!recur(sum-i-1,mask^(1<<i),m,chance^1));
                if(ans==true)
                     break;
            }
        }
        return dp[mask][chance]=ans;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
        
        memset(dp,-1,sizeof(dp));
        if(!desiredTotal)
            return true;
        int tSum=(maxChoosableInteger+1)*maxChoosableInteger/2;
          if(tSum< desiredTotal)
            return false;
        if(desiredTotal==tSum && maxChoosableInteger%2!=0)
            return true;
        if(desiredTotal==tSum && maxChoosableInteger%2==0)
            return false;
        if(desiredTotal==0)
            return true;
        int mask=(1<<maxChoosableInteger)-1;
        return recur(desiredTotal,mask,maxChoosableInteger);
        
        
    }
};
