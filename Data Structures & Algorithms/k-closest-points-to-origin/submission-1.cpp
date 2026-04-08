class Solution {
public:
    bool comparator(pair<int, int>& a, pair<int, int>& b) {
        return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first * a.first 
            + 
            a.second * a.second 
            > 
            b.first * b.first 
            + b.second * b.second;
        };

        priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        decltype(comp)> minHeap(comp);

        for (auto& point : points) {
            minHeap.push({point[0], point[1]});
        }

        vector<vector<int>> result;

        while (k--) {
            result.push_back({minHeap.top().first, minHeap.top().second});
            minHeap.pop();
        }

        return result;
    }
};
