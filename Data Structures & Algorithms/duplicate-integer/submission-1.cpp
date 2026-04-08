class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;

        for (int n : nums) {
            if (hash.count(n)) {
                hash[n]++;
            } else {
                hash[n] = 1;
            }
        }

        for (auto h : hash) {
            if (h.second > 1) {
                return true;
            }
        }
        return false;
    }
};