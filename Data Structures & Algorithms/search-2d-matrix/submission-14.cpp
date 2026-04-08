class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int start = 0, end = row - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (target > matrix[mid][col - 1]) {
                start = mid + 1;
            } else if (target < matrix[mid][0]) {
                end = mid - 1;
            } else {
                break;
            }
        }

        if (!(start <= end)) {
            return false;
        }

        int ro = (start + end) / 2;

        start = 0, end = matrix[ro].size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;

            if (matrix[ro][mid] == target) {
                return true;
            }

            if (matrix[ro][mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};
