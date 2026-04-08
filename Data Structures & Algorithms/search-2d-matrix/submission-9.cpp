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

    bool binarySearchs(vector<int>& row, int begin, int end, int target) {
        if (begin >= end) {
            return false;
        }

        int mid = (begin + end) / 2;
        if (row[mid] == target) {
            return true;
        }

        bool left, right;
        if (row[mid] > target) {
            left = binarySearch(row, begin, mid - 1, target);
        } else {
            right = binarySearch(row, mid + 1, end, target);
        }
        return left && right;
    }

    bool binarySearch(vector<int>& nums, int front, int rear, int target) {
        int mid = (front + rear) / 2;

        if (front > rear) {
            return false;
        }

        if (nums[mid] == target) {
            return true;
        }

        // if (front == rear) {
        //     return -1;
        // }

        if (nums[mid] > target) {
            binarySearch(nums, front, mid - 1, target);
        } else if (nums[mid] < target) {
            binarySearch(nums, mid + 1, rear, target);
        }
    }
};
