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
    bool isBalanceds(TreeNode* root) {
        if (!root) return true;

        int left = heights(root -> left);
        int right = heights(root -> right);

        if (abs(left - right) > 1) {
            return false;
        }
        return isBalanced(root -> left) && isBalanced(root -> right);
    }

    int heights(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + max(heights(root -> left), heights(root -> right));
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        return height(root).first;
    }

    pair<bool, int> height(TreeNode* root) {
        if (!root) {
            return {true, 0};
        }

        auto left = height(root -> left);
        auto right = height(root -> right);

        bool balanced = left.first 
        && right.first 
        && abs(left.second - right.second) <= 1;

        return {balanced, 1 + max(left.second, right.second)};
    }
};
