/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        vector<TreeNode*> nodes;
        traverse(root, nodes, root -> val);

        return nodes.size();
    }

    void traverse(TreeNode* root, vector<TreeNode*>& nodes, int maxv) {
        if (!root) {
            return;
        }

        // cout << "max: " << max << endl;
        if (root -> val >= maxv) {
            // cout << root -> val << " " << max << endl;
            // max = root -> val;
            nodes.push_back(root);
        }

        maxv = max(maxv, root -> val);

        if (root -> left)
            traverse(root -> left, nodes, maxv);
        if (root -> right)
            traverse(root -> right, nodes, maxv);
    }
};
