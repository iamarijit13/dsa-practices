class Solution {
public:
    vector<vector<int>> re;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        subsets(nums, current, 0);
        return re;
    }

    void subsets(vector<int>& nums, vector<int>& current, int i) {
        if (i == nums.size()) {
            re.push_back(current);
            return;
        }

        // re.push_back(current);
        current.push_back(nums[i]);

        subsets(nums, current, i + 1);
        current.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        subsets(nums, current, i + 1);
    }
};
