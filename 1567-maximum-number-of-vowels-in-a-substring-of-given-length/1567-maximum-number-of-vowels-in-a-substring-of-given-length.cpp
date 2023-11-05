#include<string>
#include<vector>
class Solution {
public:
    int maxVowels(string s, int k) {
        
        int count=0;
        string vowels="aeiou";

        for(int i=0; i<k; i++)
        {
            if(vowels.find(s[i])!=string::npos)count++;
        }
        
        int j=0;
        int maxx=count;

        for(int i=k; i<s.length(); i++)
        {
            if(vowels.find(s[j])!=string::npos)count--;
            if(vowels.find(s[i])!=string::npos)count++;

            j++;

            maxx=max(maxx,count);

            if(maxx==k)return maxx;

        }

        return maxx;
    }
};