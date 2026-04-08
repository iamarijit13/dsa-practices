struct pair_hash {
    size_t operator()(const pair<int, bool>& p) const {
        // Use a common hash combining technique
        return hash<int>()(p.first) ^ (hash<bool>()(p.second) << 1);
    }
};

class Solution {
public:
    int dfs(int i, bool isBuying, vector<int>& prices, 
    unordered_map<pair<int, bool>, int, pair_hash>& cache) {
        if (i >= prices.size()) {
            return 0;
        }
        if (cache.count({i, isBuying})) {
            return cache[{i, isBuying}];
        }

        int cooldown = dfs(i + 1, isBuying, prices, cache);
        if (isBuying) {
            int buy = dfs(i + 1, !isBuying, prices, cache) - prices[i];
            cache[{i, isBuying}] = max(buy, cooldown);
        } else {
            int sell = dfs(i + 2, !isBuying, prices, cache) + prices[i];
            cache[{i, isBuying}] = max(sell, cooldown);
        }
        return cache[{i, isBuying}];
    }

    int maxProfit(vector<int>& prices) {
        unordered_map<pair<int, bool>, int, pair_hash> cache;
        return dfs(0, true, prices, cache);
    }
};
