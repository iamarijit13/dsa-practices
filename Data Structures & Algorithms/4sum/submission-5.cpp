class Solution {
    vector<vector<int>> re;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> quad;
        sort(nums.begin(), nums.end());

        auto kSum = [this, &nums, &quad](auto &self, int start, int k, long long target) -> void {
            if (k != 2) {
                for (int i = start; i <= (int)nums.size() - k; i++) {
                    if (i > start && nums[i] == nums[i - 1]) continue;

                    quad.push_back(nums[i]);
                    self(self, i + 1, k - 1, target - nums[i]);
                    quad.pop_back();
                }
                return;
            }

            int l = start, r = nums.size() - 1;
            while (l < r) {
                long long sum = (long long)nums[l] + nums[r];
                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    quad.push_back(nums[l]);
                    quad.push_back(nums[r]);
                    re.push_back(quad);
                    quad.pop_back();
                    quad.pop_back();
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) l++; 
                }
            }
        };

        kSum(kSum, 0, 4, target);
        return re;
    }
};
