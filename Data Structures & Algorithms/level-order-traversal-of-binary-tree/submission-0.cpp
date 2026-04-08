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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> re;

        traverse(root, 0, re);

        return re;
    }

    void traverse(TreeNode* root, int le, vector<vector<int>>& re) {
        if (!root) {
            return;
        }

        if (re.size() > le) {
            re[le].push_back(root -> val);
        } else {
            re.push_back({root -> val});
        }

        if (root -> left) {
            traverse(root -> left, le + 1, re);
        }

        if (root -> right) {
            traverse(root -> right, le + 1, re);
        }
    }
};
