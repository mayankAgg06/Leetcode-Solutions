class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if(str1+str2!=str2+str1)return "";

        int m=str1.size();
        int n=str2.size();

        string ans= str1.substr(0,gcd(m,n));

        return ans;
        
    }
};