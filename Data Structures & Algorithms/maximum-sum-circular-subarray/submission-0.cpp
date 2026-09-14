class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax = nums[0], globalMin = nums[0], currentMin = 0, currentMax = 0;
        int total = 0;

        for (int n : nums) {
            currentMax = max(currentMax + n, n);
            currentMin = min(currentMin + n, n);

            globalMax = max(globalMax, currentMax);
            globalMin = min(globalMin, currentMin);
            total += n;
        }

        return globalMax < 0 ? globalMax : max(total - globalMin, globalMax);
    }
};