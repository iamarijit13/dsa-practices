class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int re = 0;
        unordered_set<int> nums_set(nums.begin(), nums.end());

        for (auto num : nums) {
            if (nums_set.find(num - 1) == nums_set.end()) {
                int te = 1;

                while (nums_set.find(num + te) != nums_set.end()) {
                    te++;
                }

                re = max(re, te);
            }
        }

        return re;
    }
};
