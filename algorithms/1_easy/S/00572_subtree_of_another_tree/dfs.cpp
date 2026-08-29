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
    static bool dfs_both(TreeNode *root, TreeNode *sub_root) {
        if (root == nullptr && sub_root == nullptr) {
            return true;
        }

        if (root == nullptr || sub_root == nullptr) {
            return false;
        }

        return root->val == sub_root->val &&
               dfs_both(root->left, sub_root->left) &&
               dfs_both(root->right, sub_root->right);
    }

    static bool dfs_root(TreeNode *root, TreeNode *sub_root) {
        if (root == nullptr) { return false; }

        return dfs_both(root, sub_root) ||
               dfs_root(root->left, sub_root) ||
               dfs_root(root->right, sub_root);
    }

public:
    static bool isSubtree(TreeNode *root, TreeNode *sub_root) {
        assert(root != nullptr && sub_root != nullptr);
        return dfs_root(root, sub_root);
    }
};
