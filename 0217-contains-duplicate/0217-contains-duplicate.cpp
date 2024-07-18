class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> frequency;

        int n=nums.size();

        for(int i=0; i<n; i++)
        {
            if(frequency[nums[i]])return true;

            frequency[nums[i]]=1;
        }

        return false;
    }
};