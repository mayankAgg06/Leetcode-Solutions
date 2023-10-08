class Solution {
public:
    bool isValid(string s) {

         if(s.length()<2)return false;
        
        stack<char> st1;
        
        int i=0;
        
        while(s[i]!='\0')
        {
            if(s[i]=='{')st1.push('{');
            else if(s[i]=='[')st1.push('[');
            else if(s[i]=='(')st1.push('(');
            else if(s[i]=='}')
            {
                if(!st1.empty() and st1.top()=='{')st1.pop();
                else return false;
            }
            else if(s[i]==']')
            {
                if(!st1.empty() and st1.top()=='[')st1.pop();
                else return false;
            }
            else if(s[i]==')')
            {
                if(!st1.empty() and st1.top()=='(')st1.pop();
                else return false;
            }
            
            i++;
        }
        
        if(!st1.empty())return false;
        
        return true;
        
    }
};