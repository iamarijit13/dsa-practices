class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> re(nums.size(), 1);
        int res = 1;

        for (int i = 1; i < nums.size(); i++) {
            re[i] = re[i - 1] * nums[i - 1];
        }

        res = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            re[i] *= res;
            res *= nums[i];
        }

        return re;
    }
};
