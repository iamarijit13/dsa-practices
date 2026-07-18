class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int size = cost.size();

        for (int i = size - 3; i >= 0; i--) {
            cost[i] = cost[i] + min(cost[i + 1], cost[i + 2]);
        }
        return min(cost[0], cost[1]);
    }

    int minCostClimbingStairsd(vector<int>& cost) {
        int size = cost.size();
        unordered_map<int, int> hash;
        
        int cost1 = climb(cost, 0, hash);
        int cost2 = climb(cost, 1, hash);
        return min(cost1, cost2);
    }

    int climb(vector<int>& cost, int index, unordered_map<int, int>& hash) {
        if (hash.count(index)) {
            return hash[index];
        }

        if (index >= cost.size()) {
            return 0;
        }

        int cost1 = climb(cost, index + 1, hash);
        int cost2 = climb(cost, index + 2, hash);

        return hash[index] = cost[index] + min(cost1, cost2);
    }
};
  