static bool dfs_both(struct TreeNode *root, struct TreeNode *sub_root) {
    if (root == NULL && sub_root == NULL) {
        return true;
    }

    if (root == NULL || sub_root == NULL) {
        return false;
    }

    return root->val == sub_root->val &&
           dfs_both(root->left, sub_root->left) &&
           dfs_both(root->right, sub_root->right);
}

static bool dfs_root(struct TreeNode *root, struct TreeNode *sub_root) {
    if (root == NULL) { return false; }

    return dfs_both(root, sub_root) ||
           dfs_root(root->left, sub_root) ||
           dfs_root(root->right, sub_root);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSubtree(struct TreeNode *root, struct TreeNode *sub_root) {
    if (root == NULL || sub_root == NULL) { exit(1); }

    return dfs_root(root, sub_root);
}
