static struct TreeNode* dfs(
    const int *postorder, const int postorder_idx,
    const int *inorder,
    const int lo, const int hi
) {
    if (lo > hi) { return NULL; }

    struct TreeNode* node = malloc(sizeof(*node));
    assert(node != NULL);
    node->val = postorder[postorder_idx];
    int i = hi;
    while (inorder[i] != postorder[postorder_idx]) {
        i -= 1;
    }
    node->right = dfs(postorder, postorder_idx - 1, inorder, i + 1 , hi);
    node->left = dfs(postorder, postorder_idx - (hi - i + 1), inorder, lo , i - 1);
    return node;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(
    const int *inorder, const int inorder_len,
    const int *postorder, const int postorder_len
) {
    return dfs(postorder, postorder_len - 1, inorder, 0, inorder_len - 1);
}
