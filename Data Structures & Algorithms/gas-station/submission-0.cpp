class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (sum(gas) < sum(cost)) {
            return -1;
        }
        int total = 0;
        int re = 0;

        for (int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);

            if (total < 0) {
                total = 0;
                re = i + 1;
            }
        }

        return re;
    }

    int sum(vector<int> ar) {
        int re = 0;

        for (auto x : ar) {
            re += x;
        }

        return re;
    }
};
