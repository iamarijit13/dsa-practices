class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = nums.size(), n = nums.size();
        int left = 0, right = n - 1;
        
        searchInArray(nums, left, right, target, res);
        return res;
    }

    void searchInArray(vector<int>& nums, int start, int end, int target, int &re) {
        if (start > end) {
            return;
        }

        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            re = mid;
            return;
        }

        if (nums[mid] > target) {
            re = mid;
            return searchInArray(nums, start, mid - 1, target, re);
        } else {
            return searchInArray(nums, mid + 1, end, target, re);
        }
    } 
};