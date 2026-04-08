class Solution {
public:
    int coinChanges(vector<int>& coins, int amount) {
        int re = 0, current = 0;

        traverse(coins, amount, current, re);

        return re >= 0 ? re : -1;
    }

    void traverse(vector<int>& coins, int amount, int cur, int& re) {
        if (cur > amount) {
            return;
        }

        if (cur == amount) {
            if (re == 0) {
                re = cur;
            } else {
                re = min(re, cur);
            }
        }

        for (auto x : coins) {
            traverse(coins, amount, cur + x, re);
        }
    }

    int coinChange(vector<int>& coins, int amount) { 
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int a = 1; a <= amount; a++) {
            for (auto c : coins) {
                if (a - c >= 0) {
                    dp[a] = min(dp[a], 1 + dp[a - c]);
                }
            }
        }

        return dp[amount] != amount + 1 ? dp[amount] : -1;
    }
};
