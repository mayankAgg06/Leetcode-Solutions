class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int startRow, int startCol)
    {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        q.push({startRow,startCol});

        visited[startRow][startCol]=true;

        int row[]={0,0,-1,1};
        int col[]={-1,1,0,0};

        while(!q.empty())
        {
            int frow = q.front().first;
            int fcol = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nrow = frow + row[i];
                int ncol = fcol + col[i];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='1' and !visited[nrow][ncol])
                {
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=true;
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {

        int count=0;

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1' and !visited[i][j])
                {
                    count++;
                    bfs(grid,visited,i,j);
                }
            }
        }

        return count;
        
    }
};