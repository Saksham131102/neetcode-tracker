class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n-1;
        int row;
        while(top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if(matrix[mid][m-1] < target)
                top = mid + 1;
            else if(matrix[mid][0] > target)
                bottom = mid - 1;
            else {
                row = mid;
                break;
            }
        }
        if(top > bottom)
            return false;
        int left = 0, right = m - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[row][mid] == target)
                return true;
            if(matrix[row][mid] > target)
                right = mid - 1;
            else if(matrix[row][mid] < target)
                left = mid + 1;
        }
        return false;
    }
};
