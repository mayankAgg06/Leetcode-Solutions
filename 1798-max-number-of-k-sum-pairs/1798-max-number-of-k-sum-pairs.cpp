class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        if(nums.size()<2)return 0;

        int left=0;
        int right=nums.size()-1;

        int count=0;

        while(left<right)
        {
            if((nums[left]+nums[right])<k)left++;

            else if((nums[left]+nums[right])>k)right--;

            else{
                count++;
                left++;
                right--;
            }
        }

        return count;
        
    }
};