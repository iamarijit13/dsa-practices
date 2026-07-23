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
            return parent[n];
        }

        return parent[n] = findParent(parent[n]);
    }

    bool unionByRank(int u, int v) {
        int uparent = findParent(u);
        int vparent = findParent(v);
        if (uparent == vparent) {
            return false;
        } else if (rank[uparent] > rank[vparent]) {
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
    // DisjointSet ds;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> re;
        DisjointSet ds = DisjointSet(edges.size());

        for (vector<int>& edge : edges) {
            if (!ds.unionByRank(edge[0], edge[1])) {
                re = {edge[0], edge[1]};
                return re;
            }
        }
        return re;
    }
};
