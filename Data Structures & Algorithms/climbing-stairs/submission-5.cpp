class Solution {
public:
    int climbStairs(int n) {
        // vector<int> steps(n + 1);
        // steps[1] = 1;
        // steps[2] = 2;

        // for (int i = 3; i <= n; i++) {
        //     steps[i] = steps[i - 1] + steps[i - 2];
        // }
        // return steps[n];

        vector<int> dp(n + 1, -1);
        return climb(n, dp);
    }

    int climb(int n, vector<int>& dp) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (dp[n] != -1) return dp[n];

        return dp[n] = climb(n - 1, dp) + climb(n - 2, dp);
    }
};
