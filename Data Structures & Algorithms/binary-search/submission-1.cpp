class Solution {
public:
    int binarySerach(int front, int rear, vector<int>& nums, int target) {
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
            binarySerach(front, mid - 1, nums, target);
        } else if (nums[mid] < target) {
            binarySerach(mid + 1, rear, nums, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return binarySerach(0, nums.size() - 1, nums, target);
    }
};
