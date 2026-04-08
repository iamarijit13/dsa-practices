class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> re;
        // vector<int> subset;
        // dfs(nums, 0, subset, re);
        // return re;

        vector<vector<int>> result;
        vector<int> current;

        function<void(int)> backtrack = [&](int start) {
            result.push_back(current);
            for (int i = start; i < nums.size(); ++i) {
                current.push_back(nums[i]);
                backtrack(i + 1);
                current.pop_back();
            }
        };

        backtrack(0);
        return result;
    }

    void dfs(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& re) {
        if (index >= nums.size()) {
            re.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        dfs(nums, index + 1, subset, re);
        subset.pop_back();
        dfs(nums, index + 1, subset, re);
    }
};
