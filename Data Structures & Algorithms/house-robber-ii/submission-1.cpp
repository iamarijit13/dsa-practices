class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);

        return max(nums[0], max(traverse(nums1), 
        traverse(nums2)));
    }

    int traverse(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        for (int n : nums) {
            int te = max(n + rob1, rob2);
            rob1 = rob2;
            rob2 = te;
        }

        return rob2;
    }
};
