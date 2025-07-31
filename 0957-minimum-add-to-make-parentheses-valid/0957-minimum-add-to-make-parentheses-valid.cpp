class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> helper;
        int count=0;

        for(char i:s)
        {
            if(i=='(')helper.push(i);

            else if(i==')')
            {
                if(helper.empty())count++;
                else helper.pop();
            }
        }

        return count + helper.size();
    }
};