class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre = 1, post = 1;
        vector<int> re;

        // re.push_back(pre);
        for (int i = 0; i < nums.size(); i++) {
            re.push_back(pre);
            pre *= nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            re[i] *= post;
            post *= nums[i];
        }

        for (auto x : re) {
            cout << x << " ";
        }

        return re;
    }
};
