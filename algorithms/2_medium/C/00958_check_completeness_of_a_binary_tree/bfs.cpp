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
    static bool isCompleteTree(TreeNode* root) {
        auto q = deque<TreeNode*>();
        q.push_back(root);
        bool seen_null = false;

        while (!q.empty()) {
            auto node = q.front();
            q.pop_front();

            if (node == nullptr) {
                seen_null = true;
            } else {
                if (seen_null) {
                    return false;
                }
                q.push_back(node->left);
                q.push_back(node->right);
            }
        }

        return true;
    }
};
