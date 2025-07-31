class Solution {
public:
    int longestWPI(vector<int>& hours) {

        int count=0,ans=0;
        unordered_map<int,int> tracker;

        for(int i=0; i<hours.size(); i++)
        {
            if(hours[i]>8)count++;
            else count--;

            if(count>0)ans=i+1;
            else if(tracker.count(count-1))ans = std::max(ans , i-tracker[count-1]);

            if(!tracker.count(count))tracker[count]=i;
        }
        
        return ans;
    }
};