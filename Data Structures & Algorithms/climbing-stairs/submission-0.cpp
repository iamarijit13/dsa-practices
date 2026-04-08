class Solution {
public:
    int climbStairs(int n) {
        return traverse(n, 0);
    }

    int traverse(int n, int cur) {
        if (cur == n) {
            return 1;
        }

        if (cur > n) {
            return 0;
        }

        return traverse(n, cur + 1) +
        traverse(n, cur + 2);
    }
};
