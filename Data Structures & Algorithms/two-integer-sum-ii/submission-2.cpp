class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       vector<int> re;

        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int t = numbers[l] + numbers[r];
            if (t < target) {
                l++;
            } else if (t > target) {
                r--;
            } else {
                re = {l + 1, r + 1};
                break;
            }
        }

        return re;
    }
};
