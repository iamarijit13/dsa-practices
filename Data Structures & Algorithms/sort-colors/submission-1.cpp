class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> hash(3, 0);
        vector<int> re;

        for (auto& n : nums) {
            hash[n]++;
        }

        int i = 0;
        while (hash[0] > 0) {
            nums[i++] = 0;
            hash[0]--;
        }
        while (hash[1] > 0) {
            nums[i++] = 1;
            hash[1]--;
        }
        while (hash[2] > 0) {
            nums[i++] = 2;
            hash[2]--;
        }
    }
};