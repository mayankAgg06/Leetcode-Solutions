class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        int i = 0;

        while (i < numRows) {
            triangle[i].resize(i + 1);

            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
            }
            triangle[i][0] = triangle[i][i] = 1;
            i++;
        }

        return triangle;
    }
};