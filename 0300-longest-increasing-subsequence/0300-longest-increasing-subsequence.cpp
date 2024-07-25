class Solution {
public:
    int lis(int ind, int prev,int n, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(ind == n) return 0;

        if(dp[ind][prev+1]!= -1) return dp[ind][prev+1];

        int len = 0 + lis(ind+1,prev,n,nums,dp);

        if(prev== -1 || nums[ind]> nums[prev]) len = max(len, 1 + lis(ind+1,ind,n,nums,dp));

        return dp[ind][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {

        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        
        return lis(0,-1,nums.size(),nums, dp);

    }
};