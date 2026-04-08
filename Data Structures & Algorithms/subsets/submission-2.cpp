class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> re;
        vector<int> subset;
        dfs(nums, 0, subset, re);
        return re;
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
