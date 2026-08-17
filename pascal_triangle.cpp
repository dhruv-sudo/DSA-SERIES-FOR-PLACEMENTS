class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);

        for (int i = 0; i < numRows; ++i) {
            // Every row starts and ends with 1
            triangle[i].resize(i + 1, 1);

            // Calculate the middle elements
            for (int j = 1; j < i; ++j) {
                triangle[i][j] =
                    triangle[i - 1][j - 1] +
                    triangle[i - 1][j];
            }
        }

        return triangle;
    }
};
