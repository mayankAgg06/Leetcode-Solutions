class Solution {
public:
    bool isSubsequence(string s, string t) {

        if(s.length()==0)return true;
        else if(t.length()<s.length())return false;

        int j=0;

        for(int i=0; i<=t.length(); i++)
        {
            cout<<s[j];
            if(s[j]==t[i])j++;
            if(j==s.length())return true;
        }

        return false;
        
    }
};