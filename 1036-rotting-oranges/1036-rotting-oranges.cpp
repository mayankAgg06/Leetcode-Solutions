class Solution {
    private:
    
public:
    int rotOrange(vector<vector<int>>& grid, int n, int m)
    {
        int count=0;

        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2) q.push({i,j});
            }
        }

        while(!q.empty())
        {
            int size = q.size();
            bool isSpoilt = false;

            while(size--)
            {
                int thisRow = q.front().first;
                int thisCol = q.front().second;
                q.pop();

                int x[]={-1,1,0,0};
                int y[]={0,0,-1,1};

                for(int i=0; i<4; i++)
                {
                    int row = thisRow + x[i];
                    int col = thisCol + y[i];

                    if(row<n and row>=0 and col<m and col>=0 and grid[row][col]==1)
                    {
                        grid[row][col]=2;
                        q.push({row,col});
                        isSpoilt = true;
                    }
                }
            }
            if(isSpoilt) count++;
        }

        return count;

    }
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans= rotOrange(grid,n,m);

        for(auto i:grid)
        {
            for(auto j: i)
            {
                if(j==1) return -1;
            }
        }
        return ans;
    }
};