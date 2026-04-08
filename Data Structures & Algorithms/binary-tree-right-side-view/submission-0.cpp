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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> re;
        set<int> visited;

        traverse(root, visited, 0, re);

        return re;
    }

    void traverse(TreeNode* root, set<int>& visited, int le, vector<int>& re) {
        if (!root) {
            return;
        }

        if (!visited.count(le)) {
            visited.insert(le);
            re.push_back(root -> val);
        }

        traverse(root -> right, visited, le + 1, re);
        traverse(root -> left, visited, le + 1, re);
    }
};
