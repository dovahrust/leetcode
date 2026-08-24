/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<threads.h>

#define MAX_NODES 100
#define Q_CAP (2 * MAX_NODES + 1)

thread_local static struct TreeNode *q[Q_CAP];

bool isCompleteTree(struct TreeNode *root) {
    size_t front = 0;
    q[0] = root;
    size_t back = 1;
    bool seen_null = false;

    while (front != back) {
        struct TreeNode *node = q[front];
        front += 1;

        if (node == NULL) {
            seen_null = true;
        } else {
            if (seen_null) {
                return false;
            }

            if (back == Q_CAP || back + 1 == Q_CAP) {
                fprintf(stderr, "number of nodes should be less than or equal to 100");

            }
            q[back] = node->left;
            q[back + 1] = node->right;
            back += 2;
        }
    }

    return true;
}
