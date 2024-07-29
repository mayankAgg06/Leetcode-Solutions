class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int,int> nextGreater;

        for(auto num : nums2)
        {
            while(!st.empty() and st.top()<num)
            {
                nextGreater[st.top()]=num;
                st.pop();
            }

            st.push(num);
        }

        vector<int> ans;

        for(auto num: nums1)
        {
            if(nextGreater[num]) ans.push_back(nextGreater[num]);

            else ans.push_back(-1);
        }

        return ans;
        
    }
};