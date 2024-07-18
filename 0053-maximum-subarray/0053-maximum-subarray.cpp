class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currMax=0;
        int maxm = INT_MIN;
        
        for(int i=0; i<nums.size(); i++)
        {
            currMax+=nums[i];

            if(maxm < currMax) maxm = currMax;

            if(currMax<0) currMax=0;
        }

        return maxm;
    }
};