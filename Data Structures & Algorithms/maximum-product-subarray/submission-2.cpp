class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], curMin = 1, curMax = 1;

        for (int n : nums) {
            // if (n == 0) {
            //     curMin = 1, curMax = 1;
            //     continue;
            // }
            
            int te = curMax;
            curMax = max(max(n * curMax, n * curMin), n);
            curMin = min(min(n * te, n * curMin), n);

            res = max(res, curMax);
        }

        return res;
    }
};
