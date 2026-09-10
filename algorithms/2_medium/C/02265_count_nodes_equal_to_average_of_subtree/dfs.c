struct pair {
    int sum;
    int cnt;
};

static struct pair dfs(struct TreeNode *node, int *restrict res) {
    if (node == NULL) { return (struct pair){ 0 }; }

    const struct pair l = dfs(node->left, res);
    const struct pair r = dfs(node->right, res);
    const int sum = l.sum + r.sum + node->val;
    const int cnt = l.cnt + r.cnt + 1;
    if (node->val == sum / cnt) {
        *res += 1;
    }

    return (struct pair){ .sum = sum, .cnt = cnt };
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int averageOfSubtree(struct TreeNode* root) {
    int res = 0;
    dfs(root, &res);
    return res;
}
