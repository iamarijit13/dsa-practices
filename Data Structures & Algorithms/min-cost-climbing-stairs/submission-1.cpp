class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        dfs(cost, dp, 0);
        min(cost[0], cost[1]);
        return min(dp[0], dp[1]);
    }

    int dfs(vector<int>& cost, vector<int>& dp, int index) {
        if (dp[index] != -1) {
            return dp[index];
        }
        
        if (index >= cost.size()) {
            return 0;
        }

        dp[index] = cost[index] + min(dfs(cost, dp, index + 1), 
            dfs(cost, dp, index + 2));
        return dp[index];
    }
};
