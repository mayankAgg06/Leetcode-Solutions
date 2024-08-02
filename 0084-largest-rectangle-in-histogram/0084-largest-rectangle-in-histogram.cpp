class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n= heights.size();

        vector<int> leftSmaller(n+1,-1);
        vector<int> rightSmaller(n+1,-1);

        stack<int> st, st2;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() and heights[st.top()]>=heights[i]) st.pop();

            if(st.empty()) {
                st.push(i);
                leftSmaller[i]=0;
            }
            else
            {
                leftSmaller[i]=st.top()+1;
                st.push(i);
            }
        }

        for(int i=n-1; i>=0; i--)
        {
            while(!st2.empty() and heights[st2.top()]>=heights[i]) st2.pop();

            if(st2.empty()) {
                st2.push(i);
                rightSmaller[i]=n-1;
            }
            else
            {
                rightSmaller[i]=st2.top()-1;
                st2.push(i);
            }
        }

        int maxi = INT_MIN;

        for(int i=0; i<n; i++)
        {
            maxi = max ( maxi , (rightSmaller[i]-leftSmaller[i]+1)*heights[i]);
        }

        return maxi;
    }
};