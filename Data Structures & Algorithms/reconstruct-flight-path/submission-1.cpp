class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, vector<string>> adj;
        for (auto ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        vector<string> re = {"JFK"};
        dfs("JFK", re, adj, tickets.size() + 1);

        return re;
    }

    bool dfs(string src, vector<string>& re, unordered_map<string, vector<string>>& adj, int target) {
        if (re.size() == target) {
            return true;
        }

        if (!adj.count(src)) {
            return false;
        }

        vector<string> temp = adj[src];
        for (int i = 0; i < temp.size(); i++) {
            string v = temp[i];
            adj[src].erase(adj[src].begin() + i);
            re.push_back(v);

            if (dfs(v, re, adj, target)) {
                return true;
            }
            adj[src].insert(adj[src].begin() + i, v);
            re.pop_back();
        }
        return false;
    }
};
