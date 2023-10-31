class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int curr=0;

        for(int i=0; i<k; i++)
        {
            curr+=nums[i];
        }

        int maxx=curr;

        for(int i=k; i<nums.size(); i++)
        {
            curr+=nums[i]-nums[i-k];

            maxx=max(maxx,curr);
        }

        return (double)maxx/k;
        
    }
};