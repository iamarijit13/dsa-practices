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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if ((!p || !q) || (p -> val != q -> val)) {
            return false;
        }

        return isSameTree(p -> left, q -> left) 
        && isSameTree(p -> right, q -> right);
    }

    bool isSameTrees(TreeNode* p, TreeNode* q) {
        vector<int> pt, qt;

        traverse(p, pt);
        traverse(q, qt);

        for (int i = 0; i < pt.size(); i++) {
            if (pt[i] != qt[i]) {
                return false;
            }
        }

        return true;
    }

    void traverse(TreeNode* root, vector<int>& travel) {
        if (!root) {
            travel.push_back(INT_MIN);
            return;
        }

        travel.push_back(root -> val);

        traverse(root -> left, travel);
        traverse(root -> right, travel);
    }
};
