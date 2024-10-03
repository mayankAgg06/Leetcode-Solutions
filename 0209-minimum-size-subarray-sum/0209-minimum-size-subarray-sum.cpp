class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int i=0,j=0;
        int n=nums.size();
        int sum=nums[0];
        int minSize=INT_MAX;

        while(j<n)
        {
            if(i==j and nums[i]>=target) return 1;
            else if(i!=j and sum>=target)
            {
                minSize= min(minSize, j-i+1);
                sum-=nums[i];
                i++;
            }
            else{
                j++;
                if(j<n)sum+=nums[j];
            }
        }

        // if(sum>=target) minSize= min(minSize, j-i);

        if(minSize==INT_MAX)return 0;

        return minSize;
    }
};