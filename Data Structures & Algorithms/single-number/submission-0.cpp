class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int re = 0;

        for (auto& n : nums) {
            re = re ^ n;
        }

        return re;
    }
};
