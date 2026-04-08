class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());
        stack<double> fleet;

        for (auto& p : pair) {
            double reach = (double)(target - p.first) / p.second;

            if (fleet.size() >= 1 && fleet.top() >= reach) {
                continue;
            }

            fleet.push(reach);
        }

        return fleet.size();
    }
};
