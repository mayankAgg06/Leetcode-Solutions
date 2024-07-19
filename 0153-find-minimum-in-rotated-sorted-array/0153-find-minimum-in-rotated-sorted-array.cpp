class Solution {
public:
    int findMin(vector<int>& nums) {
        int start= 0;
        int end=nums.size()-1;

        int mid = (start+end)/2;

        while(start<end)
        {
            mid = start + (end-start)/2;

            if(nums[mid]<nums[end])end=mid;

            else start=mid+1;
        }

        return nums[start];
    }
};