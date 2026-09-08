static int dfs_h_right(struct TreeNode* curr) {
    if (curr == NULL) { return 0; }

    return 1 + dfs_h_right(curr->right);
}

static int dfs_h_left(struct TreeNode* curr) {
    if (curr == NULL) { return 0; }

    return 1 + dfs_h_left(curr->left);
}

static int dfs(struct TreeNode* curr) {
    const int h_left = dfs_h_left(curr);
    const int h_right = dfs_h_right(curr);

    if (h_right == h_left) {
        return (1 << h_left) - 1;
    } else {
        return 1 + dfs(curr->left) +  dfs(curr->right);
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    return dfs(root);
}
