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
    vector<int> inorderTraversals(TreeNode* root) {
        vector<int> re;

        auto inorder = [&re](auto& self, TreeNode *root) {
            if (!root) return;

            self(self, root -> left);
            re.push_back(root -> val);
            self(self, root -> right);
        };
        inorder(inorder, root);
        return re;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> re;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur -> left;
            }

            cur = st.top();
            re.push_back(cur -> val);
            st.pop();
            
            cur = cur -> right;
        }
        return re;
    }
};