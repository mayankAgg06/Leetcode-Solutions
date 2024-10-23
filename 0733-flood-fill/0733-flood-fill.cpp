class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;

        q.push({sr,sc});

        int start = image[sr][sc];
        if(start==color) return image;

        int n=image.size();
        int m= image[0].size();

        image[sr][sc]=color;

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            int rowwise[] = {-1,1,0,0};
            int colwise[] = {0,0,-1,1};

            for(int itr=0; itr<4; itr++)
            {
                int row = i+rowwise[itr];
                int col = j+colwise[itr];

                if(row<n and col<m and row>=0 and col>=0 and image[row][col]==start)
                {
                    image[row][col]=color;
                    q.push({row,col});
                }
            }
        }

        return image;
    }
};