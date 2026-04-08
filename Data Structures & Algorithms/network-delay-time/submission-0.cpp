class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (auto time : times) {
            edges[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});
        set<int> visited;
        int re = 0;

        while (!minHeap.empty()) {
            auto el = minHeap.top();
            minHeap.pop();

            int w1 = el.first;
            int v1 = el.second;

            if (visited.count(v1)) {
                continue;
            }

            visited.insert(v1);
            re = w1;

            if (edges.count(v1)) {
                for (auto x : edges[v1]) {
                    minHeap.push({w1 + x.second, x.first});
                }
            }
        }

        return visited.size() == n ? re : -1;
    }
};
