class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        int n= word1.length();
        int m= word2.length();

        string merged;

        while(i<n and j<m)
        {
            merged+=word1[i];
            i++;
            merged+=word2[j];
            j++;
        }
        while(j<m)
        {
            merged+=word2[j];
            j++;
        }
        while(i<n)
        {
            merged+=word1[i];
            i++;
        }

        return merged;
    }
};