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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> rt, srt;

        // traverse(root, rt);
        // traverse(subRoot, srt);

        // for (int i = 0; i < rt.size(); i++) {
        //     if (rt[i] == srt[0]) {
        //         int k = i;
        //         for (int j = 0; j < srt.size(); j++) {
        //             if (srt[j] != rt[k]) {
        //                 return false;
        //             }
        //             k++;
        //         }
        //         return true;
        //     }
        // }

        // return false;

        if (!subRoot) {
            return true;
        }

        if (!root) {
            return false;
        }

        if (isSame(root, subRoot)) {
            return true;
        }

        return isSubtree(root -> left, subRoot) ||
        isSubtree(root -> right, subRoot);

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

    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if ((!p || !q) || (p -> val != q -> val)) {
            return false;
        }

        return isSame(p -> left, q -> left) && isSame(p -> right, q -> right);
    }
};
