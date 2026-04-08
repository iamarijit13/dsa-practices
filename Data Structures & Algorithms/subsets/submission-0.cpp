class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> re;
        vector<int> subset;

        traverse(nums, re, subset, 0);

        return re;
    }

    void traverse(vector<int>& nums, vector<vector<int>>& re, vector<int>& subset, int index) {
        if (index >= nums.size()) {
            re.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        traverse(nums, re, subset, index + 1);

        subset.pop_back();
        traverse(nums, re, subset, index + 1);
    }
};
