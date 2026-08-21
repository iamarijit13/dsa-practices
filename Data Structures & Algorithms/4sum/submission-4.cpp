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

// The missing valid quadruplet is caused by two distinct bugs in your loop limits and duplicate skipping logic:
// 1. Incorrect Loop Upper Bound (i < nums.size() - k): When nums.size() is 6 and k = 4, nums.size() - k evaluates to 2. The condition i < 2 forces the loop to stop at index 0, missing valid starting positions like index 1 (which holds the second 1 needed to form [-1, 1, 1, 1]). Change it to i <= (int)nums.size() - k.
// 2. Wrong Duplicate Check Pointer (nums[l] == nums[r]): In your while loop inside the two-pointer block, you are comparing nums[l] to nums[r] instead of comparing nums[l] to its previous value nums[l - 1]. Comparing l to r causes the loop to skip remaining valid pairs prematurely when duplicate values exist at both ends. Change it to nums[l] == nums[l - 1].
// Here is the fully fixed code:
// class Solution {
//     vector<vector<int>> re;
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<int> quad;
//         sort(nums.begin(), nums.end());

//         // Use long long for target to prevent integer overflow on large sums
//         auto kSum = [this, &nums, &quad](auto &self, int start, int k, long long target) -> void {
//             if (k != 2) {
//                 // FIXED 1: Changed '<' to '<=' so the final valid start index isn't skipped
//                 for (int i = start; i <= (int)nums.size() - k; i++) {
//                     if (i > start && nums[i] == nums[i - 1]) continue;

//                     quad.push_back(nums[i]);
//                     self(self, i + 1, k - 1, target - nums[i]);
//                     quad.pop_back();
//                 }
//                 return;
//             }

//             int l = start, r = nums.size() - 1;
//             while (l < r) {
//                 long long sum = (long long)nums[l] + nums[r];
//                 if (sum < target) {
//                     l++;
//                 } else if (sum > target) {
//                     r--;
//                 } else {
//                     quad.push_back(nums[l]);
//                     quad.push_back(nums[r]);
//                     re.push_back(quad);
//                     quad.pop_back();
//                     quad.pop_back();
//                     l++;
//                     // FIXED 2: Compare against nums[l - 1] instead of nums[r]
//                     while (l < r && nums[l] == nums[l - 1]) l++; 
//                 }
//             }
//         };

//         kSum(kSum, 0, 4, target);
//         return re;
//     }
// };