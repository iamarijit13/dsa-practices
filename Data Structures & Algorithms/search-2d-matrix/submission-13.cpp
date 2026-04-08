class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& m : matrix) {
            if (binarySearch(m, 0, m.size() - 1, target)) {
                return true;
            }
        }
        return false;
    }

    bool binarySearch(vector<int>& row, int begin, int end, int target) {
        if (begin > end) {
            return false;
        }

        int mid = (begin + end) / 2;
        if (row[mid] == target) {
            return true;
        }

        if (row[mid] > target) {
            binarySearch(row, begin, mid - 1, target);
        } else {
            binarySearch(row, mid + 1, end, target);
        }
    }

    bool binarySearchs(vector<int>& nums, int front, int rear, int target) {
        int mid = (front + rear) / 2;

        if (front > rear) {
            return false;
        }

        if (nums[mid] == target) {
            return true;
        }

        if (nums[mid] > target) {
            binarySearch(nums, front, mid - 1, target);
        } else if (nums[mid] < target) {
            binarySearch(nums, mid + 1, rear, target);
        }
    }
};
