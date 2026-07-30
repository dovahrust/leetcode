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
    static int dfs(TreeNode* node, int& cnt) {
        if (node == nullptr) {
            return numeric_limits<int>::min();
        }

        const int val = node->val;
        const int lval = dfs(node->left, cnt);
        const int rval = dfs(node->right, cnt);
        const int max_child = std::max(lval, rval);
        if (val >= max_child) {
            cnt += 1;
            return val;
        } else {
            return max_child;
        }
    }
public:
    static int countDominantNodes(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
};
