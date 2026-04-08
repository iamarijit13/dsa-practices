class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, res = INT_MAX;
        int total = 0;

        for (r = 0; r < nums.size(); r++) {
            total += nums[r];
            while (total >= target) {
                res = min(res, r - l + 1);
                total -= nums[l];
                l++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};