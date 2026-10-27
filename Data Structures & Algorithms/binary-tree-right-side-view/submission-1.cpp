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
        unordered_set<int> visit;

        auto iterate = [&](auto &self, TreeNode *root, int le) {
            if (!root) return;

            if (!visit.count(le)) {
                visit.insert(le);
                re.push_back(root -> val);
            }
            self(self, root -> right, le + 1);
            self(self, root -> left, le + 1);
        };
        iterate(iterate, root, 0);
        return re;
    }
};
