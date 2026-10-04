class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;
        vector<int> divisions(k, 0);

        auto backtrack = [&nums, &divisions, k, target](auto &self, int index) {
            if (nums.size() == index) return true;

            for (int div = 0; div < k; div++) {
                if (divisions[div] + nums[index] <= target) {
                    divisions[div] += nums[index];
                    if (self(self, index + 1)) return true;
                    divisions[div] -= nums[index];
                }
                if (divisions[div] == 0) break;
            }
            return false;
        };

        return backtrack(backtrack, 0);
    }
};