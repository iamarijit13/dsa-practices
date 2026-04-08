class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n + 1, -1);
        // dp[n] = 1;
        // dp[n - 1] = 2;

        // for (int i = n - 2; i >= 0; i--) {
        //     dp[i] = dp[n + 1] + dp[n + 2];
        // }
        // return dp[0];

        return dfs(dp, n);
    }

    int dfs(vector<int>& dp, int n) {
        if (dp[n] != -1) {
            return dp[n];
        }
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }

        dp[n] = dfs(dp, n - 1) + dfs(dp, n - 2);
        return dp[n];
    }
};
