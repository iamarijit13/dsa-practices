class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> hash;
        return max(step(nums, 0, hash), step(nums, 1, hash));
    }

    int step(vector<int>& nums, int index, unordered_map<int, int>& hash) {
        if (index >= nums.size()) {
            return 0;
        }
        if (index == nums.size() - 1 || index == nums.size() - 2) {
            return nums[index];
        }

        if (hash.count(index)) {
            return hash[index];
        }

        return hash[index] = nums[index] + max(step(nums, index + 2, hash), step(nums, index + 3, hash));
    }
};
