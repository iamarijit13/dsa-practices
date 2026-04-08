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
int getIndex(vector<int>& vec, int target) {
    auto it = find(vec.begin(), vec.end(), target);
    return distance(vec.begin(), it);
}

    vector<int> subvec(vector<int>::iterator begin, vector<int>::iterator end) {
        return vector<int>(begin, end);
    }

    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        int mid = getIndex(inorder, preorder[0]);

        root->left = buildTree(
            subvec(preorder.begin() + 1, preorder.begin() + 1 + mid),
            subvec(inorder.begin(), inorder.begin() + mid)
        );

        root->right = buildTree(
            subvec(preorder.begin() + 1 + mid, preorder.end()),
            subvec(inorder.begin() + mid + 1, inorder.end())
        );

        return root;
    }
};
