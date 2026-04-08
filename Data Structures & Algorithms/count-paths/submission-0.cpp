struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        // Use a common hash combining technique
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        unordered_map<pair<int, int>, int, pair_hash> cache;
        return dfs(m, n, 0, 0, cache);
    }

    int dfs(int m, int n, int r, int c, 
    unordered_map<pair<int, int>, int, pair_hash> cache) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return 0;
        }

        if (cache.count({r, c})) {
            return cache[{r, c}];
        }
        if (r == m - 1 && c == n - 1) {
            return 1;
        }

        return dfs(m, n, r + 1, c, cache) 
        + dfs(m, n, r, c + 1, cache);
    }
};
