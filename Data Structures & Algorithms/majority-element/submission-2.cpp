class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int re = nums[0];

        for (auto& x : nums) {
            if (hash.count(x)) {
                hash[x]++;
            } else {
                hash[x] = 1;
            }

            if (hash.count(re) && hash[x] > hash[re]) {
                re = x;
            }
        }
        
        return re;
    }
};