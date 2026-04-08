class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);

        lis[nums.size() - 1] = 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        return *max_element(lis.begin(), lis.end());
    }
};
