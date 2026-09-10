static struct TreeNode *dfs(struct TreeNode *node, const int lo, const int hi) {
    if (node == NULL) { return NULL; }

    struct TreeNode *left = dfs(node->left, lo, hi);
    struct TreeNode *right = dfs(node->right, lo, hi);

    if (node->val < lo) {
        free(node);
        return right;
    } else if (node->val > hi) {
        free(node);
        return left;
    } else {
        node->left = left;
        node->right = right;
        return node;
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
struct TreeNode* trimBST(struct TreeNode* root, const int lo, const int hi) {
    return dfs(root, lo, hi);
}
