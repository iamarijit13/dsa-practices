class Solution {
    vector<vector<int>> paths;
    set<pair<int, int>> visit;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        priority_queue<
            tuple<int, int, int>, 
            vector<tuple<int, int, int>>, 
            greater<tuple<int, int, int>>
        > pq;
        set<pair<int, int>> visit;

        pq.push({0, 0, 0});
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!pq.empty()) {
            auto [diff, r, c] = pq.top();
            pq.pop();

            if (visit.count({r, c})) continue;
            visit.insert({r, c});
            if (r == row - 1 && c == col - 1) return diff;

            for (auto [dr, dc] : directions) {
                int newr = r + dr, newc = c + dc;
                if (newr < 0 || newc < 0 || newr == row || newc == col || visit.count({newr, newc})) continue;
                int maxDiff = max(diff, abs(heights[r][c] - heights[newr][newc]));
                pq.push({maxDiff, newr, newc});
            }
        }
        return -1;
    }
};