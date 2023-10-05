class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minm=INT_MAX;
        int profit=INT_MIN;

        for(int i=0; i<prices.size(); i++)
        {
            minm=min(prices[i],minm);

            profit= max(profit,prices[i]-minm);
        }

        return profit;
        
    }
};