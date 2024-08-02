
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int maxi=INT_MIN;
        int n = nums.size();

        vector<int> solution;

        deque<int> dq;
        
        for(int i=0; i<n; i++)
        {
            if(!dq.empty() and dq.front()==i-k) dq.pop_front();

            while(!dq.empty() and nums[dq.back()]<nums[i]) dq.pop_back();

            dq.push_back(i);

            if(i>=k-1) solution.push_back(nums[dq.front()]);
        }

        
        return solution;
        
    }
};