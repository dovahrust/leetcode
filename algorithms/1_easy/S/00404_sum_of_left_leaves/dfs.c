int dfs(struct TreeNode* curr, const bool is_left_child) {
    if (curr == NULL) {
        return 0;
    }

    int sum = 0;

    if (is_left_child && curr->left == NULL && curr->right == NULL) {
        sum += curr->val;
    }

    sum += dfs(curr->left, true);
    sum += dfs(curr->right, false);

    return  sum;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    return dfs(root, false);
}
