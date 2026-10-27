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

        auto iterate = [&](auto &self, TreeNode *root, int le) {
            if (!root) return;

            if (re.size() > le) re[le].push_back(root -> val);
            else re.push_back({root -> val});

            if (root -> left) self(self, root -> left, le + 1);
            if (root -> right) self(self, root -> right, le + 1);
        };

        iterate(iterate, root, 0);
        return re;
    }
};
