static struct TreeNode* dfs(
    const int *preorder, const int preorder_idx,
    const int *inorder,
    const int lo, const int hi
) {
    if (lo > hi) {
        return NULL;
    }

    struct TreeNode* node = malloc(sizeof(*node));
    assert(node != NULL);
    node->val = preorder[preorder_idx];
    int i = lo;
    while (inorder[i] != preorder[preorder_idx]) {
        i += 1;
    }
    node->left = dfs(preorder, preorder_idx + 1, inorder, lo , i - 1);
    node->right = dfs(preorder, preorder_idx + i - lo + 1, inorder, i + 1 , hi);
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
    const int *preorder, const int preorder_len,
    const int *inorder, const int inorder_len
) {
    return dfs(preorder, 0, inorder, 0, inorder_len - 1);
}
