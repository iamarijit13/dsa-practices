class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    int findParent(int n) {
        if (parent[n] == n) {
            return n;
        }

        return parent[n] = findParent(parent[n]);
    }

    bool unionByRank(int u, int v) {
        int parentu = findParent(u);
        int parentv = findParent(v);

        if (parentu == parentv) return false;
        else if (rank[parentu] > rank[parentv]) {
            parent[parentv] = parentu;
        } else if (rank[parentv] > rank[parentv]) {
            parent[parentu] = parentv;
        } else {
            parent[parentv] = parentu;
            rank[parentu]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds(accounts.size());
        unordered_map<string, int> emailToAcc;

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if (emailToAcc.count(email)) {
                    ds.unionByRank(i, emailToAcc[email]);
                } else {
                    emailToAcc[email] = i;
                }
            }
        }

        map<int, vector<string>> emailGroup;
        for (const auto& [email, accId] : emailToAcc) {
            int leader = ds.findParent(accId);
            emailGroup[leader].push_back(email);
        }

        // Build result
        vector<vector<string>> res;
        for (auto& [accId, emails] : emailGroup) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[accId][0]);
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(merged);
        }

        return res;

    }
};