class Solution {
public:

    bool dfs(vector<vector<int>>& graph, int start, vector<int>& colour, int col)
    {
        colour[start]=col;

        for(auto i:graph[start])
        {
            if(colour[i]== -1)
            {
                if(!dfs(graph,i,colour,!col)) return false;
            }
            else if(colour[i]==colour[start])return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int v = graph.size();
        vector<int> colour(v,-1);

        for(int i=0; i<v; i++)
        {
            if(colour[i]== -1)
            {
                if(!dfs(graph,i,colour,0)) return false;
            }
        }

        return true;
        
    }
};