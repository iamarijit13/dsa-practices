class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k %= n;
        if (k == 0) return;

        for (int i = 0; i < n - k; i++) {
            nums.push_back(nums[i]);
        }

        nums.assign(nums.begin() + (n - k), nums.end());
    }
};
