class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=nums1.size()-1;
        
        if(j<0)return;
        if(i<0 and j>=0)
        {
           while(j>=0)
            {
                nums1[k]=nums2[j];
                    k--;
                    j--;
            } 
        }
        
        while(i>=0 and j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            else
            {
                nums1[k]=nums2[j];
                k--;
                j--;
            }
        }
        
        while(i>=0)
        {
           nums1[k]=nums1[i];
            k--;
            i--; 
        }
        while(j>=0)
        {
            nums1[k]=nums2[j];
                k--;
                j--;
        }
    }
};