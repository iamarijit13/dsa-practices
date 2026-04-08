class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
       int n = nums.size();
       vector<int> re(n * 2);

       for (int i = 0; i < n; i++) {
            re[i] = re[i + n] = nums[i];
       }

       return re;
    }
};