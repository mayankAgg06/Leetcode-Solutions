class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Considering majority element is always present, no other number can exist more than n/2 times. So we can decrease the count everytime we encounter a different number. this will help us achieve the element.

        int ele=0;
        int count=0;

        for(int i=0; i<nums.size(); i++)
        {
            if(count==0)
            {
                ele=nums[i];
            }

            if(nums[i]==ele)count++;
            else count--;

        }

        return ele;
        
    }
};