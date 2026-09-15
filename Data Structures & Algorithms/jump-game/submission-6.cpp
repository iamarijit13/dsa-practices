class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> cache;

        auto iterate = [&nums, &cache, n](auto &self, int index) -> bool {
            if (index >= n) return false;
            if (index == n - 1) return true;
            if (cache.count(index)) return cache[index];

            for (int i = 1; i <= nums[index]; i++) {
                cache[index] = self(self, index + i);
                if (cache[index]) return true;
            }
            return cache[index];
        };

        return iterate(iterate, 0);
    }
};
