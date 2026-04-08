class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int curSub = 0;

        for (auto x : nums) {
            if (curSub < 0) {
                curSub = 0;
            }
            curSub += x;
            maxSub = max(maxSub, curSub);
        }

        return maxSub;
    }
};
