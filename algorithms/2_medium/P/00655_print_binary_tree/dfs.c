static inline uint32_t max_uint(const uint32_t a, const uint32_t b) {
    return a > b ? a : b;
}

static uint32_t dfs_height(struct TreeNode* node) {
    if (node == NULL) { return 0; }
    return 1 + max_uint(dfs_height(node->left), dfs_height(node->right));
}

static void fill_res(struct TreeNode* node, char*** res, const uint32_t level, int32_t lo, int32_t hi) {
    if (node == NULL) { return; }
    const int32_t mid = lo + (hi - lo) / 2;
    if (asprintf(&res[level][mid], "%d", node->val) == -1) {
        fprintf(stderr, "asprintf failed\n");
        exit(1);
    }
    fill_res(node->left, res, level + 1, lo, mid - 1);
    fill_res(node->right, res, level + 1, mid + 1, hi);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** printTree(struct TreeNode* root, int* return_rows, int** return_cols_data) {
    const uint32_t rows = dfs_height(root);
    const uint32_t cols = (1u << rows) - 1;
    char*** res = malloc((size_t)rows * sizeof(*res));
    if (res == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    for (uint32_t i = 0; i < rows; i += 1) {
        res[i] = calloc((size_t)cols, sizeof(**res));
        if (res[i] == NULL) {
            fprintf(stderr, "alloc fail");
            exit(1);
        }
    }

    fill_res(root, res, 0, 0, (int32_t)cols - 1);
    int* cols_data = malloc((size_t)rows * sizeof(*cols_data));
    if (cols_data == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    for (uint32_t i = 0; i < rows; i += 1) { cols_data[i] = (int)cols; }
    *return_cols_data = cols_data;
    *return_rows = (int)rows;
    for (uint32_t i = 0; i < rows; i += 1) {
        for (uint32_t j = 0; j < cols; j += 1) {
            if (res[i][j] == NULL) {
                res[i][j] = malloc(sizeof(char));
                if (res[i][j] == NULL) {
                    fprintf(stderr, "alloc fail");
                    exit(1);
                }
                res[i][j][0] = '\0';
            }
        }
    }
    return res;
}
