class Solution {
public:
    void dfs( unordered_map<string,vector<string>>& adj, vector<string> & itinerary, string start)
    {

        while(!adj[start].empty())
        {
            string next=adj[start].back();
            adj[start].pop_back();
            dfs(adj,itinerary,next);
        }
        itinerary.push_back(start);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;

        for(auto& ticket: tickets) //cant make a copy
        {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for(auto& temp:adj) //cant make a copy, hence by reference
        {
            sort(temp.second.rbegin(),temp.second.rend()); 
            //this will sort the graph in reverse lexicographical order, minm will be pop_back
        }

        vector<string> itinerary;

        dfs(adj,itinerary,"JFK");

        reverse(itinerary.begin(),itinerary.end());

        return itinerary;

    }
};