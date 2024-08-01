class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 0;
        int end = 1000000000;
        int k = start + (end-start)/2;

        while(start<=end)
        {
            k = start + (end-start)/2;
            double count=0;

            for(int pile:piles) count += ceil((double)pile/k);

            if(count>h) start=k+1;

            else end=k-1;
        }

        return start;
    }
};