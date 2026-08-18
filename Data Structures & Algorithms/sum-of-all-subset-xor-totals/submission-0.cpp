// class Solution {
//     int re = 0;
//     vector<vector<int>> subsets;
// public:
//     int subsetXORSum(vector<int>& nums) {

//         auto findSubsets = [this, &nums](auto &self, vector<int>& cur, int index) {
//             if (index == nums.size()) {
//                 this -> subsets.push_back(cur);
//             }

//             cur.push_back(nums[index]);
//             findSubsets(self, cur, index + 1);
//             cur.pop_back();
//             findSubsets(self, cur, index + 1);
//         };

//         findSubsets(findSubsets, cur, 0);

//         for (auto &subset : subsets) {
//             int xr = 0;
//             for (auto & n : subset) {
//                 xr = xr ^ n;
//             }
//             re += xr;
//         }

//         return re;
//     }
// };

class Solution {
    int re = 0;
    vector<vector<int>> subsets;
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> cur;

        auto findSubsets = [this, &nums](auto &self, vector<int>& cur, int index) -> void {
            if (index == nums.size()) {
                subsets.push_back(cur);
                return; // 1. Added missing return to prevent out-of-bounds access below
            }

            cur.push_back(nums[index]);
            self(self, cur, index + 1); // 2. Changed 'findSubsets' to 'self'
            cur.pop_back();
            self(self, cur, index + 1); // 3. Changed 'findSubsets' to 'self'
        }; // 4. Added missing semicolon (and removed '()' immediate invocation)

        findSubsets(findSubsets, cur, 0); // 5. Explicitly called with required arguments

        for (auto &subset : subsets) {
            int xr = 0;
            for (auto &n : subset) {
                xr = xr ^ n;
            }
            re += xr;
        }

        return re;
    }
};
