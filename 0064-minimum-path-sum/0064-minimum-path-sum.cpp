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

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return pathSum(grid,n,m,dp);
    }
};