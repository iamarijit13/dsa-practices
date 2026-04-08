class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int re = sum(nums);
        if (re % 2) {
            return false;
        }

        set<int> dp;
        dp.insert(0);

        for (int i = nums.size() - 1; i >= 0; i--) {
            set<int> nextDp;
            for (auto& x : dp) {
                nextDp.insert(x + nums[i]);
                nextDp.insert(x);
            }
            dp = nextDp;
        }
        return dp.count(re / 2) ? true : false;
    }

    int sum(vector<int>& nums) {
        int re = 0;
        for (auto& n : nums) {
            re += n;
        }
        return re;
    }
};
