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
    static int dfs(const TreeNode* curr, int& sum) {
        if (curr == nullptr) {
            return 0;
        }

        const int left = dfs(curr->left, sum);
        const int right = dfs(curr->right, sum);

        sum += std::abs(left - right);

        return left + curr->val + right;
    }
public:
    static int findTilt(const TreeNode* root) {
        int sum = 0;

        dfs(root, sum);

        return sum;
    }
};
