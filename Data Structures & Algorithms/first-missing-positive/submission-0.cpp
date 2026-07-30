class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int re = 1;

        for (int i = 1; i <= numset.size() + 1; i++) {
            if (!numset.count(i)) {
                re = i;
                break;
            }
        }
        return re;
    }
};