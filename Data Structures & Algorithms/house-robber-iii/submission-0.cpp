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
    int rob(TreeNode* root) {
        if (!root) return -1;

        auto traverse = [](auto &self, TreeNode *root) -> pair<int, int> {
            if (!root) return {0, 0};

            pair<int, int> leftPair = self(self, root -> left);
            pair<int, int> rightPair = self(self, root -> right);

            int withRoot = root -> val + leftPair.second + rightPair.second;
            int withoutRoot = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);

            pair<int, int> re = {withRoot, withoutRoot};
            return re;
        };

        pair<int, int> re = traverse(traverse, root);
        return max(re.first, re.second);
    }
};