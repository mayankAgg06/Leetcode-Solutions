class Solution {
public:
    int pathSum(vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp)
    {
        if(n==0 and m==0) return dp[0][0] = grid[0][0];

        if(n<0 || m<0) return INT_MAX;

        if(dp[n][m]!=-1)return dp[n][m];
        
        int up = pathSum(grid,n-1,m,dp);
        int right = pathSum(grid,n,m-1,dp);

        return dp[n][m]= grid[n][m]+min(up,right);

    }
    int minPathSum(vector<vector<int>>& grid) {

        int n=grid.size()-1;
        int m=grid[0].size()-1;

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        dp[0][0]= grid[0][0];

        for(int i=1; i<=n; i++) dp[i][0] = dp[i-1][0] + grid[i][0];

        for(int j=1; j<=m; j++) dp[0][j] = dp[0][j-1] + grid[0][j];

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};