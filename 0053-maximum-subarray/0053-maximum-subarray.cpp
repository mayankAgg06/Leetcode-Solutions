class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currSum = 0;
        int maxSum = INT_MIN;

        for (auto num : nums) {
            currSum += num;
            if (currSum > maxSum)
                maxSum = currSum;

            if (currSum < 0)
                currSum = 0;
        }

        return maxSum;
    }
};