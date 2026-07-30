static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static int dfs(struct TreeNode* node, int* cnt)
{
    if (node == NULL) {
        return INT_MIN;
    }

    const int val = node->val;
    const int lval = dfs(node->left, cnt);
    const int rval = dfs(node->right, cnt);
    const int max_child = max_int(lval, rval);
    if (val >= max_child) {
        *cnt += 1;
        return val;
    } else {
        return max_child;
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
int countDominantNodes(struct TreeNode* root)
{
    int cnt = 0;
    dfs(root, &cnt);
    return cnt;
}
