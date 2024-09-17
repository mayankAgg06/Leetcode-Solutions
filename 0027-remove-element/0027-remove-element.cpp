class Solution {
public:
    int removeElement(vector<int>& a, int val) {

        int i=0,j=0;

        while(j<a.size())
        {
            if(a[j]!=val)
            {
                a[i++]=a[j];
            }
            j++;
        }

        return i;
        
    }
};