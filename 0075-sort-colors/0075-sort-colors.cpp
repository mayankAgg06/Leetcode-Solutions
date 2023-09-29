class Solution {
public:
    void sortColors(vector<int>& nums) {
         int zeroes=0;
         int ones=0;
         int twos=0;

         for(int i=0; i<nums.size(); i++)
         {
            if(nums[i]==0)zeroes++;
            else if(nums[i]==1)ones++;
            else twos++;
         }

         int i=0;
         while(zeroes)
         {
            nums[i]=0;
            i++;
            zeroes--;
         }
         while(ones)
         {
            nums[i]=1;
            i++;
            ones--;
         }
         while(twos)
         {
            nums[i]=2;
            i++;
            twos--;
         }
        
    }
};