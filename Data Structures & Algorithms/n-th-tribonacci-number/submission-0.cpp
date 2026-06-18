class Solution {
public:
    int tribonacci(int n) {
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
};