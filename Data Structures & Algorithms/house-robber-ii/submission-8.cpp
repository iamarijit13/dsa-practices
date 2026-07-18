class Solution {
public:

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        unordered_map<int, int> hash1;
        unordered_map<int, int> hash2;
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(max(step(nums1, 0, hash1), step(nums1, 1, hash1)), 
            max(step(nums2, 0, hash2), step(nums2, 1, hash2)));
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
