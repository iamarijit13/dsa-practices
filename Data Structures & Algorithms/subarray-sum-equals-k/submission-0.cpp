class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        int re = 0, sum = 0;

        prefix.insert({0, 1});
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (prefix.count(sum - k)) {
                re += prefix[sum - k];
            }
            prefix[sum]++;
        }
        return re;
    }
};