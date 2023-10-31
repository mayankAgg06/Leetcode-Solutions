class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int size=nums.size();

        if(size<3)return false;

        int smallest=INT_MAX;
        int middle=INT_MAX;

        for(int i=0; i<size; i++)
        {
            if(nums[i]>middle)return true;

            else if(nums[i]>smallest and nums[i]<middle) middle=nums[i];

            else if(nums[i]<smallest) smallest=nums[i];
        }

        return false;
        
    }
};