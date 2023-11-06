class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int midZero=-1;
        int i=0;
        int j=0;
        int ans=0;
        int n=nums.size();

        while(j<n)
        {
            if(nums[j]==0)
            {
                ans=max(ans,j-i-1);
                i=midZero+1;
                midZero=j;
            }

            j++;
        }
        ans=max(ans,j-i-1);

        return ans;
    }
};