class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }

        int mid = (left + right) / 2; 

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[left] <= nums[mid]) {
            if (target > nums[mid] || target < nums[left]) {
                binarySearch(nums, target, mid + 1, right);
            } else {
                binarySearch(nums, target, left, mid - 1);
            }
        } else {
            if (target < nums[mid] || target > nums[right]) {
                binarySearch(nums, target, left, mid - 1);
            } else {
                binarySearch(nums, target, mid + 1, right);
            }
        }
    }
}; 
