class Solution {
public:
    int findMin(vector<int> &nums) {
        int re = nums[0];
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                re = min(re, nums[l]);
                break;
            }

            int mid = (l + r) / 2;
            re = min(re, nums[mid]);
            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return re;
    }
};
