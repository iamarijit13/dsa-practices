class Solution {
public:
    int rob(vector<int>& nums) {
        // int odd = 0, even = 0;
        // traverse(nums, 0, odd);
        // traverse(nums, 1, even);
        // return max(odd, even);

        int rob1 = 0, rob2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            int te = max(rob1 + nums[i], rob2);

            rob1 = rob2;
            rob2 = te;
        }

        return rob2;
    }

    void traverse(vector<int>& houses, int cr, int& re) {
        if (cr >= houses.size()) {
            return;
        }

        re += houses[cr];

        traverse(houses, cr + 2, re);
    }
};
