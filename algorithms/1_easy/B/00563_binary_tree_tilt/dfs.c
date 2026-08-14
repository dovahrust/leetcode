static inline int abs_int(const int a) {
    return a < 0 ? -a : a;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int dfs(const struct TreeNode*, int*);

int findTilt(const struct TreeNode *root) {
    int sum = 0;

    dfs(root, &sum);

    return sum;
}

static int dfs(const struct TreeNode *curr, int *sum) {
    if (curr == NULL) {
        return 0;
    }

    const int left = dfs(curr->left, sum);
    const int right = dfs(curr->right, sum);

    *sum += abs_int(left - right);

    return left + curr->val + right;
}
