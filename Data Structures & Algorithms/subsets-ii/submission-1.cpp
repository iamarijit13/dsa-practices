class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        vector<int> current;
        
        auto subset = [&nums, &re, &current](auto &self, int index) {
            if (index == nums.size()) {
                re.push_back(current);
                return;
            }

            current.push_back(nums[index]);

            self(self, index + 1);
            current.pop_back();
            while (index + 1 < nums.size() && nums[index] == nums[index + 1]) index++;
            self(self, index + 1);
        };

        subset(subset, 0);
        return re;
    }
};
