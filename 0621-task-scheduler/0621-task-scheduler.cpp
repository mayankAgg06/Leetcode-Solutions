class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;

        int max_freq=0;

        for(auto ch : tasks){
            freq[ch]++;

            max_freq= max( max_freq, freq[ch]);
        }

        int max_count=0;

        for(auto each : freq) if(each.second == max_freq) max_count++;

        int intervals = max((int)tasks.size(), ((max_freq-1)*(n+1) + max_count));

        return intervals;

    }
};