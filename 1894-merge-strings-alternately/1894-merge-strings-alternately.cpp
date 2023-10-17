class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string finalstr="";
        
        int i=0,j=0;

        while(i<word1.length() and j<word2.length())
        {
            finalstr.push_back(word1[i]);
            i++;
            finalstr.push_back(word2[j]);
            j++;
        }
        while(i<word1.length())
        {
            finalstr.push_back(word1[i]);
            i++;
        }
        while(j<word2.length())
        {
            finalstr.push_back(word2[j]);
            j++;
        }

        return finalstr;
        
    }
};