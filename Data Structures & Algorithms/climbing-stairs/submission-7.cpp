class Solution {
public:
    int climbStairs(int n) {
        // vector<int> hash(n + 2, INT_MAX);
        unordered_map<int, int> hash;
        return climb(n, 1, hash);
    }

    int climb(int n, int c, unordered_map<int, int>& hash) {
        // cout << hash[c] << endl;
        if (hash.count(c)) {
            return hash[c];
        }

        if (c == n + 1) {
            return 1;
        }

        if (c > n + 1) {
            return 0;
        }

        // return 
        hash[c] = climb(n, c + 1, hash) + climb(n, c + 2, hash);

        return hash[c];
    }
};
