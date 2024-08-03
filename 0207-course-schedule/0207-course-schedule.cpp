class Solution {
public:
    bool bfs(vector<int>& visited, unordered_map<int,vector<int>>& adj, int node)
    {
        visited[node]=-1;

        queue<pair<int,int>> q;

        q.push({node,-1});

        while(!q.empty())
        {
            int front = q.front().first;
            q.pop();

            for(auto i:adj[front])
            {
                if(visited[i]==-2)
                {
                    visited[i]=front;
                    q.push({i,front});
                }
                else if(visited[i]!= front) return false;
            }
            
        }

        return true;
    }

    bool dfs(vector<int>& visited, unordered_map<int,vector<int>>& adj, int node,int parent)
    {
        visited[node]= parent;

        for(auto i: adj[node])
        {
            if(visited[i]==-2)
            {
                if(!dfs(visited,adj,i,node)) return false;
            } 
            else if(visited[i]!= node) return false;
        }

        return true;
    }

    bool kahnsAlgo(unordered_map<int,vector<int>>& adj, int numCourses)
    {
        vector<int> indegree(numCourses,0);
        queue<int> q;

        vector<int> solution;

        for(int i=0; i<numCourses; i++)
        {
            for(auto course: adj[i]) indegree[course]++;
        }

        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            solution.push_back(front);

            for(auto neighbour: adj[front])
            {
                indegree[neighbour]--;

                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }

        return (solution.size()==numCourses);
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;

        for(auto each : prerequisites)
        {
            adj[each[1]].push_back(each[0]);
        }

        vector<int> visited(numCourses,-2);

        // for(auto i: adj)
        // {
        //     if(visited[i.first]==-2)
        //     {
        //         // if(!bfs(visited,adj,i.first)) return false;
        //         if(!dfs(visited,adj,i.first,-1)) return false;
        //     }
        // }

        // return true;

        return kahnsAlgo(adj,numCourses);
    }
};