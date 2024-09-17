class Solution {
public:
    int hIndex(vector<int>& citations) {
        
       int n = citations.size();

       vector<int> temp(n+1,0);

       for(int i=0; i<n; i++)
       {
            if(citations[i]>=n)temp[n]++;

            else temp[citations[i]]++;
       }

       int totalVal = 0;

       for(int i=n; i>=0; i--)
       {
            totalVal+=temp[i];

            if(totalVal>=i)return i;
       }

       return 0;

    }
};