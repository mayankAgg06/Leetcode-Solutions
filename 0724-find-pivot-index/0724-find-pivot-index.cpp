class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum+= nums[i];
        }
        
        int sum1=sum;
        int sum2=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum1-= nums[i];
            
            if(sum1==sum2)
            {
                return i;
            }
            
            sum2+=nums[i];
        }
     return -1;   
    }
};