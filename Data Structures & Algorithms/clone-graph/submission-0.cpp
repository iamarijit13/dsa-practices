/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToNew;

        return dfs(oldToNew, node);
        // return oldToNew[0];
    }

    Node* dfs(unordered_map<Node*, Node*>& oldToNew, Node* node) {
        if (!node) {
            return NULL;
        }
        
        if (oldToNew.find(node) != oldToNew.end()) {
            return oldToNew[node];
        }

        Node* copy = new Node(node -> val);
        oldToNew.insert({node, copy});

        for (auto n : node -> neighbors) {
            copy -> neighbors.push_back(dfs(oldToNew, n));
        }

        return copy;
    }
};
