class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int nodes) {
        rank.resize(nodes + 1, 0);
        parent.resize(nodes + 1);
        for (int i = 0; i < nodes + 1; i++) {
            parent[i] = i;
        }
    } 

    int findParent(int node) {
        if (parent[node] == node) return node;

        return parent[node] = findParent(parent[node]);
    }

    bool unionByRank(int u, int v) {
        int uparent = findParent(u);
        int vparent = findParent(v);

        if (uparent == vparent) {
            return false;
        }
        
        if (rank[uparent] > rank[vparent]) {
            parent[vparent] = uparent;
        } else if (rank[vparent] > rank[uparent]) {
            parent[uparent] = vparent;
        } else {
            parent[vparent] = uparent;
            rank[uparent]++;
        }
        return true;
    }
};

class Solution {
public:
    int countComponentss(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int node = 0; node < n; ++node) {
            if (!visit[node]) {
                dfs(adj, visit, node);
                res++;
            }
        }
        return res;
    }

    void dfs(const vector<vector<int>>& adj, vector<bool>& visit, int node) {
        visit[node] = true;
        for (int nei : adj[node]) {
            if (!visit[nei]) {
                dfs(adj, visit, nei);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int res = n;

        for (auto edge : edges) {
            if (ds.unionByRank(edge[0], edge[1])) res--;
        }
        return res;
    }
};
