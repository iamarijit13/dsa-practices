class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x, re;

        while (left <= right) {
            int mid = (left + right) / 2;

            long long gs = (long long) mid * mid;

            if (gs == x) {
                return mid;
            } else if (gs > x) {
                right = mid - 1;
            } else if (gs < x) {
                left = mid + 1;
                re = mid;
            }
        }

        return re;
    }
};