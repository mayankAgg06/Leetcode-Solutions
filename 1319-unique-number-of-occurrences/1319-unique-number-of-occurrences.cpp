class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int,int> freq;

        for(int i=0; i<arr.size(); i++)
        {
            freq[arr[i]]++;
        }

        unordered_set<int> check;

        for(auto num:freq)
        {
            check.insert(num.second);
        }

        return (check.size()==freq.size());
        
    }
};