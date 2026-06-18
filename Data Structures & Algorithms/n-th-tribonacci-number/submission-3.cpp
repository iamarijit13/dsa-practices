class Solution {
    unordered_map<int, int> dp;
public:
    int tribonaccii(int n) {
        vector<int> t = {0, 1, 1};

        if (n <= 2) {
            return t[n];
        }

        for (int i = 3; i <= n; i++) {
            vector<int> tx = t;
            t[2] = sum(tx), t[1] = tx[2], t[0] = tx[1];
        }
        return(t[2]);
    }

    int sum(vector<int>& t) {
        int s = 0;
        for (auto& x : t) {
            s += x;
        }
        return s;
    }

    int tribonacciii(int n) {
        if (n <= 2) {
            return n == 0 ? 0 : 1;
        }

        return tribonacciii(n - 1) + tribonacciii(n - 2) + tribonacciii(n - 3);
    }

    int tribonacci(int n) {
        if (n <= 2) {
            return n == 0 ? 0 : 1;
        }
        if (dp.count(n)) return dp[n];

        dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];
    }
};