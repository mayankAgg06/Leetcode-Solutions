class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> checkSolution;

        for(int i=0; i<nums.size(); i++)
        {
            if(checkSolution.find(target-nums[i])!=checkSolution.end())
            {
                return {i,checkSolution[target-nums[i]]};
            }
            checkSolution[nums[i]]=i;
        }

        return {};
    }
};