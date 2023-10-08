class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
         int i=0;
        vector<vector<int>> sol;
        
        sort(a.begin(),a.end());
        
        while(i<a.size()-2)
        {
            int left=i+1;
            int right=a.size()-1;
            while(left<right)
            {
                if((a[left]+a[right]+a[i])==0)
                {
                    vector<int> soll;
                    soll.push_back(a[i]);
                    soll.push_back(a[left]);
                    soll.push_back(a[right]);
                    
                    sol.push_back(soll);
                    
                    left++;right--;
                    
                    while(left < right and a[left]==a[left-1])left++;
                    while(left < right and a[right]==a[right+1])right--;
                    
                }
                else if((a[left]+a[right]+a[i])<0) left++;
                else if ((a[left]+a[right]+a[i])>0) right--;
            }
            i++;
            while(i< a.size()-2 and a[i]==a[i-1])i++;
        }
        
        return sol;
        
    }
};