class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pqHelp;
    priority_queue<int> pq;
    int count;
    KthLargest(int k, vector<int>& nums) {
        count=k;
        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        for(int i=0; i<k and !pq.empty(); i++)
        {
            pqHelp.push(pq.top());
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);

        pqHelp.push(pq.top());

        pq.pop();

        if(pqHelp.size()>count) pqHelp.pop();

        return pqHelp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */