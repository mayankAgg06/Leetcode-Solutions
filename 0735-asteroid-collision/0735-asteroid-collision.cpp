class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> positive;
        stack<int> negative;

        for(int i=asteroids.size()-1; i>=0; i--)
        {
            if(asteroids[i]>0)
            {
                if(negative.empty()) positive.push(asteroids[i]);

                else
                {
                    while(!negative.empty() and (asteroids[i]- abs(negative.top()))>0)negative.pop();

                    if(negative.empty()) positive.push(asteroids[i]);
                    else
                    {
                        if(asteroids[i]==abs(negative.top()))negative.pop();
                    }
                }
            }
            else negative.push(asteroids[i]);
        }

        vector<int> ans;

        
        while(!negative.empty())
        {
            ans.push_back(negative.top());
            negative.pop();
        }
        while(!positive.empty())
        {
            ans.push_back(positive.top());
            positive.pop();
        }
        return ans;
        
    }
};