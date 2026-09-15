class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = 0, globalMax = nums[0];

        for (int n : nums) {
            currentMax = max(currentMax + n, n);
            globalMax = max(currentMax, globalMax);
        }

        return globalMax;
    }
};
