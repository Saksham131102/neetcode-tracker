class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int r = 0, c = m - 1;
        while(c >= 0 && r < n) {
            if(matrix[r][c] == target)
                return true;
            if(matrix[r][c] < target)
                r++;
            else if(matrix[r][c] > target)
                c--;
        }
        return false;
    }
};
