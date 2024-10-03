class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char,int> mp;

        for(auto itr:magazine)
        {
            mp[itr]++;
        }

        for(auto itr:ransomNote)
        {
            if(!mp[itr])return false;

            mp[itr]--;
        }

        return true;
        
    }
};