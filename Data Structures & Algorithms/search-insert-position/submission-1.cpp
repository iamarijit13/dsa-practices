class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = nums.size(), n = nums.size();
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = (right + left) / 2;

            if (nums[mid] == target) return mid;

            if (nums[mid] > target) {
                res = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        return res;
    }
};