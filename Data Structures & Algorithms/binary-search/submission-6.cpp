class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchInArray(nums, 0, nums.size() - 1, target);
    }

    int searchInArray(vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }

        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] > target) {
            return searchInArray(nums, start, mid - 1, target);
        } else {
            return searchInArray(nums, mid + 1, end, target);
        }
    } 
};
