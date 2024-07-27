class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {

        vector<vector<int>> points=peaks;

        for(int i=0; i<peaks.size(); i++)
        {
            points[i][0]-=peaks[i][1];
            points[i][1]+=peaks[i][0];
        }

        sort(points.begin(),points.end());

        int visible=0;
        int i=0;

        while(i<points.size())
        {
            visible++;

            if(i==points.size()-1) return visible;
            
            if(points[i][0]==points[i+1][0])visible--;

            int currentEnd= points[i][1];

            while(i<points.size()-1 and currentEnd>= points[i+1][1]) i++;

            i++;

        }        

        return visible;
    }
};