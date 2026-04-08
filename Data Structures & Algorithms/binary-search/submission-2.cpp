class Solution {
public:
    int binarySerach(vector<int>& nums, int target, int front, int rear) {
        if (front > rear) {
            return -1;
        }
        int mid = (front + rear) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] > target) {
            binarySerach(nums, target, front, mid - 1);
        } else {
            binarySerach(nums, target, mid + 1, rear);
        }
    }

    int search(vector<int>& nums, int target) {
        return binarySerach(nums, target, 0, nums.size() - 1);
    }
};
