static int dfs_h_right(TreeNode* curr) {
    if (curr == nullptr) { return 0; }

    return 1 + dfs_h_right(curr->right);
}

static int dfs_h_left(TreeNode* curr) {
    if (curr == nullptr) { return 0; }

    return 1 + dfs_h_left(curr->left);
}

static int dfs(TreeNode* curr) {
    const int h_left = dfs_h_left(curr);
    const int h_right = dfs_h_right(curr);

    if (h_right == h_left) {
        return (1 << h_left) - 1;
    } else {
        return 1 + dfs(curr->left) +  dfs(curr->right);
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        return dfs(root);
    }
};
