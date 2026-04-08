class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> re;

        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                re = {m[nums[i]], i};
            } else {
                m.insert({(target - nums[i]), i});
            }
        }
        return re;
    }
};
