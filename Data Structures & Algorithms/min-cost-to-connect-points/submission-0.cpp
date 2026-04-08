class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int dist = abs(points[i][0] - points[j][0]) 
                + abs(points[i][1] - points[j][1]);

                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        
        int re = 0;
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        minH.push({0, 0});

        while(visited.size() < points.size()) {
            pair<int, int> front = minH.top();
            minH.pop();
            int cost = front.first;
            int i = front.second;
            if (visited.count(i)) {
                continue;
            }

            re += cost;
            visited.insert(i);
            for (auto x : adj[i]) {
                int minCost = x.first;
                int index = x.second;
                if (!visited.count(index)) {
                    minH.push({minCost, index});
                }
            }
        }
        return re;
    }
};
