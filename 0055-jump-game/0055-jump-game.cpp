class Solution {
public:
    bool jumping(int ind, vector<int > &nums, vector<int> &dp)
    {
        if(ind>=nums.size()-1)return true;
        
        if(dp[ind]!=-1) return dp[ind];

        // cout<<"on index "<<ind;

        if((nums.size()-ind-1)<nums[ind]) return dp[ind]=1;

        for(int j=1; j<=nums[ind]; j++)
        {
            // cout<<"testing index "<<ind+j;
            if(jumping(ind+j,nums,dp)) return dp[ind]=1;
        }

        return dp[ind]=0;
    }
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();

        vector<int> dp(n,-1);

        if(n==1)return true;

        dp[n-1]=true;

        for(int j=1; j<=nums[0]; j++)
        {
            // cout<<"testing number"<<j;
            if(jumping(j,nums,dp)) return true;
        }

        return false;
       
    }
};