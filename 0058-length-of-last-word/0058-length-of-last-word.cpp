class Solution {
public:
    int lengthOfLastWord(string s) {

        string help = "";

        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i]==' ' and help.length()!=0)break;

            else if(s[i]!=' ')help+=s[i];
        }

        return help.length();
        
    }
};