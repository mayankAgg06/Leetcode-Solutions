class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count=0;
        int maxCount=0;

        for(auto i:nums)
        {
            if(i==1)count++;
            
            else
            {
                maxCount=max(count,maxCount);
                count=0;
            } 
        }

        maxCount=max(count,maxCount);
        return maxCount;
    }
};