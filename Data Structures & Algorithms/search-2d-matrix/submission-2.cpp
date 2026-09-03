class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m - 1;
        while(0<=row && row<n && 0<=col && col<m) {
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] < target)
                row++;
            else if(matrix[row][col] > target)
                col--;
        }
        return false;
    }
};
