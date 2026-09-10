/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static int *restrict dfs(struct TreeNode* node, int distance, int *restrict res) {
    if (node == NULL) { return NULL; }

    int *restrict l = dfs(node->left, distance, res);
    int *restrict r = dfs(node->right, distance, res);

    if (l == NULL && r == NULL) {
        int *restrict vec = calloc((size_t)(distance + 1), sizeof(*vec));
        vec[0] = 1;
        return vec;
    } else if (l == NULL || r == NULL) {
        int *restrict vec = l == NULL ? r : l;
        for (int i = distance; i >= 1; i -= 1) {
            vec[i] = vec[i - 1];
        }
        vec[0] = 0;
        return vec;
    } else {
        for (int i = 0; i <= distance; i += 1) {
            for (int j = 0; j <= distance; j += 1) {
                if (i + j + 2 <= distance) {
                    *res += (l[i] * r[j]);
                }
            }
        }

        for (int i = distance; i >= 1; i -= 1) {
            l[i] = l[i - 1] + r[i - 1];
        }
        l[0] = 0;
        free(r);
        return l;
    }
}

int countPairs(struct TreeNode* root, int distance) {
    int res = 0;
    void *tmp = dfs(root, distance, &res);
    free(tmp);
    return res;
}
