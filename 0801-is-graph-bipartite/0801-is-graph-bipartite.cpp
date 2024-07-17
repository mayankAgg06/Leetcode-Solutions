class Solution {
public:

    bool bfs(vector<vector<int>>& graph, int start, vector<int>& colour)
    {
        queue<int> q;
        q.push(start);

        colour[start]=0;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto i : graph[front])
            {
                if(colour[i] == -1)
                {
                    colour[i] = !colour[front];
                    q.push(i);
                }

                else if(colour[i]==colour[front]) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        queue<int> q;
        q.push(0);
        
        int v = graph.size();
        vector<int> colour(v,-1);

        for(int i=0; i<v; i++)
        {
            if(colour[i]== -1)
            {
                if(!bfs(graph,i,colour)) return false;
            }
        }

        return true;
        
    }
};