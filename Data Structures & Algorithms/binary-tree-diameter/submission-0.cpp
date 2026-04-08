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
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        traverse(root, max);
        return max;
    }

    int traverse(TreeNode* root, int& maximum) {
        if (!root) {
            return 0;
        }

        int left = traverse(root -> left, maximum);
        int right = traverse(root -> right, maximum);

        maximum = max(maximum, left + right);
        return 1 + max(left, right);
    }
};
