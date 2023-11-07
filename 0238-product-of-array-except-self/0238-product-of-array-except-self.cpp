class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        vector<int> leftpr(n,1);
        vector<int> rightpr(n,1);

        for(int i=1;i<n; i++)
        {
            leftpr[i]=leftpr[i-1]*nums[i-1];
        }
        for(int i=n-2; i>=0; i--)
        {
            rightpr[i]=rightpr[i+1]*nums[i+1];
        }

        for(int i=0; i<n; i++)
        {
            nums[i]=leftpr[i]*rightpr[i];
        }

        return nums;
        
    }
};