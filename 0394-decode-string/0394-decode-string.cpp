class Solution {
public:
    string decodeString(string s) {

        stack<pair<int,string>> helper;
        string ans;

        int i=0;

        while(i<s.size())
        {
            if(s[i]>='0' and s[i]<='9')
            {
                int j=i;
                while(s[i]>='0' and s[i]<='9')
                {
                    i++;
                }
                int num= stoi(s.substr(j, i-j));
                helper.push({num,""});
            }
            else if(s[i]>='a' and s[i]<='z')
            {
                int j=i;
                while(s[i]>='a' and s[i]<='z') i++;

                string curr= s.substr(j,i-j);
                if(helper.empty()) ans+=curr;
                else helper.top().second+=curr;
            }
            else if(s[i]==']')
            {
                int itr=helper.top().first;
                string curr= "";

                while(itr--)curr+=helper.top().second;


                helper.pop();

                if(helper.empty())ans+=curr;

                else
                helper.top().second+=curr;

                i++;
            }
            else i++;
        }

        return ans;
        
    }
};