class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        vector<int> re;

        for (const auto& n : nums) {
            if (hash.count(n)) {
                hash[n]++;
            } else {
                hash.insert({n, 1});
            }
        }

        for (const auto& [k, v] : hash) {
            if (v > floor(nums.size() / 3)) {
                re.push_back(k);
            }
        }

        return re;
    }
};