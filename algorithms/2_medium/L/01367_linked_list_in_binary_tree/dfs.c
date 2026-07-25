static bool dfs_check(struct ListNode* ll, struct TreeNode* node)
{
    if (ll == NULL) {
        return true;
    }

    if (node == NULL) {
        return false;
    }

    return node->val == ll->val &&  (dfs_check(ll->next, node->left) || dfs_check(ll->next, node->right));
}

static bool dfs_tree(struct ListNode* ll, struct TreeNode* node)
{
    if (dfs_check(ll, node)) {
        return true;
    }

    if (node == NULL) {
        return false;
    }

    return dfs_tree(ll, node->left) ||
           dfs_tree(ll, node->right);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSubPath(struct ListNode* head, struct TreeNode* root)
{
    return dfs_tree(head, root);
}
