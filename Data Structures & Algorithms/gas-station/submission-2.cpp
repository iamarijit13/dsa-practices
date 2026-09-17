class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(cost.begin(), cost.end(), 0) > accumulate(gas.begin(), gas.end(), 0)) return -1;

        int total = 0, re = 0;
        for (int i = 0; i < cost.size(); i++) {
            total += gas[i] - cost[i];
            if (total < 0) {
                total = 0;
                re = i + 1;
            }
        }
        return re;
    }
};
