class Solution {
public:
    string reverseWords(string s) {

        int i=s.length()-1;
        string ans="";
        string helper="";

        for(int j=i; j>=0; j--)
        {
            if(s[j]==' ')
            {
                if(helper.size()!=0)
                {
                    reverse(helper.begin(),helper.end());
                    ans+=helper;
                    ans+=" ";
                    helper="";
                }
            }
            else
            {
                helper+=s[j];
            }
        }

        if(helper.size()!=0)
        {
            reverse(helper.begin(),helper.end()); 
            ans+=helper;
        }
        else if(ans.size()!=0)ans.pop_back();

        return ans;

        
        
    }
};