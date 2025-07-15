class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int net=0,s=0;
            int n=gas.size();
            
            int t_gas=0, t_cost=0;
            for(int i=0; i<n; i++)
            {
                net+=gas[i];
                net-=cost[i];
                t_gas+=gas[i];
                t_cost+=cost[i];
                if(net<0)
                {
                    s=i+1;
                    net=0;
                }
            }
            
        if(t_gas-t_cost >=0)
        {
            return s;
        }
        
        return -1;
        
    }
};