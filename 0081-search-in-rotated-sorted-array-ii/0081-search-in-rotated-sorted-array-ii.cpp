class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int start=0;
        int end= nums.size()-1;

        int mid= start + (end-start)/2;

        while(start<=end)
        {
            int mid= start + (end-start)/2;
            if(nums[mid]==target) return true;

            if(nums[mid]==nums[start] and nums[mid]==nums[end])
            {
                start++;
                end--;
                continue;
            }

            if(nums[start]<=nums[mid])
            {
                if(nums[start]<=target and target<=nums[mid]) end=mid-1;

                else start=mid+1;
            } 
            else
            {
                if(nums[end]>=target and target>=nums[mid])start = mid+1;

                else end=mid-1;
            }
        }
        
        return false;
    }
};