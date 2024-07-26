class Solution {
public:
    int robbing(vector<int>& nums, int ind, vector<int>& dp)
    {
        if(ind<0)return 0;
        if(ind==0) return nums[0];

        if(dp[ind] != -1) return dp[ind];
        
        int pick = nums[ind]+robbing(nums,ind-2,dp);
        int notPick = robbing(nums,ind-1,dp);
        
        return dp[ind]=max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
	    vector<int> dp(n,-1);
	    return robbing(nums,n-1,dp);

    }
};