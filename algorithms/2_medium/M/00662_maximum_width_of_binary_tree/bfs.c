#include <threads.h>

#define MAX_ALLOWED_NODES 3000
#define MAX_Q_LEN (MAX_ALLOWED_NODES + 10)

struct pair {
    size_t pos;
    struct TreeNode *node;
};

thread_local static struct pair q[MAX_Q_LEN];
static size_t q_head;
static size_t q_len;

inline static void q_push(const struct pair p) {
    if (q_head + q_len == MAX_Q_LEN) {
        perror("invalid input");
        exit(1);
    }
    q[q_head + q_len] = p;
    q_len += 1;
}

inline static void q_init(const struct pair p) {
    q[0] = p;
    q_len = 1;
    q_head = 0;
}

inline static struct pair q_pop() {
    if (q_len == 0) {
        perror("q cant be empty");
        exit(1);
    }
    q_head += 1;
    q_len -= 1;
    return q[q_head - 1];
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int widthOfBinaryTree(struct TreeNode *root) {
    if (root == NULL) { return 0; }

    q_init((struct pair){ .pos = 0, .node = root });
    size_t res = 0;

    while (q_len > 0) {
        const size_t level_len = q_len;
        res = MAX(res, q[q_head + q_len - 1].pos - q[q_head].pos + 1);
        for (size_t step = 0; step < level_len; step += 1) {
            const struct pair p = q_pop();

            if (p.node->left != NULL) {
                q_push((struct pair){ .pos = p.pos * 2, .node = p.node->left });
            }
            if (p.node->right != NULL) {
                q_push((struct pair){ .pos = (p.pos * 2) + 1, .node = p.node->right });
            }
        }
    }

    return (int)res;
}
