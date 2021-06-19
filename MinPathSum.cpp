//leetcode 64 
//Minimum path sum ,path can be only right or down 
//its solved usind dp iteratively
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        const int INF =1e+5; //using this for min function
        int H =grid.size();
        int W =grid[0].size();
        vector<vector<int>> dp(H,vector<int>(W));
        for(int rows=0;rows<H;rows++)
            for(int cols=0;cols<W;cols++)
            {
                if(rows==0 && cols==0)
                      dp[rows][cols]=grid[rows][cols];  // for first cell in grid
                else
                {
                    dp[rows][cols]=grid[rows][cols]+ min((rows==0?INF:dp[rows-1][cols]),cols==0?INF:dp[rows][cols-1]);
                }
                
            }
        return dp[H-1][W-1];
        
    }
};
