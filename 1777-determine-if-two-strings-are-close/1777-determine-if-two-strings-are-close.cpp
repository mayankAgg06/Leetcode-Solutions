class Solution {
public:
    bool closeStrings(string word1, string word2) {

        unordered_map<int,int> map1,map2;

        if(word1.length()!=word2.length()) return false;

        for(int i=0; i<word1.size(); i++) map1[word1[i]]++;

        for(int i=0; i<word2.size(); i++) map2[word2[i]]++;

        for(int i=0; i<word1.size(); i++)
        {
            if(map2.find(word1[i])==map2.end())return false;
        }
        for(int i=0; i<word2.size(); i++)
        {
            if(map1.find(word2[i])==map1.end())return false;
        }

        vector<int> vect1,vect2;

        for(auto i:map1) vect1.push_back(i.second);

        for(auto i:map2) vect2.push_back(i.second);

        sort(vect1.begin(),vect1.end());
        sort(vect2.begin(),vect2.end());

        return vect1==vect2;
        
    }
};