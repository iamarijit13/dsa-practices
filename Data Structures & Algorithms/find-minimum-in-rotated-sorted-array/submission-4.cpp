class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        int re = nums[0];

        while (start <= end) {
            int mid = (start + end) / 2;
            re = min(nums[mid], re);

            if (nums[end] > nums[start]) {
                re =  min(nums[start], re);
                break;
            }
            if (nums[mid] >= nums[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return re;
    }
};
