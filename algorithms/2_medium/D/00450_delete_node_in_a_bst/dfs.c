inline static struct TreeNode *get_the_most_left_child(struct TreeNode *node) {
    if (node == NULL) { return NULL; }

    while (node->left != NULL) {
        node = node->left;
    }

    return node;
}

static struct TreeNode *dfs(struct TreeNode *node, const int key) {
    if (node == NULL) { return NULL; }

    if (node->val < key) {
        node->right = dfs(node->right, key);
        return node;
    } else if (node->val > key) {
        node->left = dfs(node->left, key);
        return node;
    } else {
        struct TreeNode *l = node->left;
        struct TreeNode *r = node->right;
        free(node);

        if (l == NULL) {
            return r;
        } else if (r == NULL) {
            return l;
        } else {
            struct TreeNode *most_left_child = get_the_most_left_child(r);
            most_left_child->left = l;
            return r;
        }
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
struct TreeNode* deleteNode(struct TreeNode *root, const int key) {
    return dfs(root, key);
}
