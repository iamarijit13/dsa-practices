class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {{}};
        }

        vector<int> te = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(te);
        vector<vector<int>> re;

        for (const auto& p : perms) {
            for (int i = 0; i <= p.size(); i++) {
                vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);
                re.push_back(p_copy);
            }
        }

        return re;
    }
};
