class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       for (auto x : matrix) {
            int re = binarySearch(0, x.size() - 1, x, target);
            if(re != -1) {
                return true;
            }   
       } 

       return false;
    }

    int binarySearch(int front, int rear, vector<int>& nums, int target) {
        int mid = (front + rear) / 2;

        if (front > rear) {
            return -1;
        }

        if (nums[mid] == target) {
            return mid;
        }

        if (front == rear) {
            return -1;
        }

        if (nums[mid] > target) {
            binarySearch(front, mid - 1, nums, target);
        } else if (nums[mid] < target) {
            binarySearch(mid + 1, rear, nums, target);
        }
    }
};
