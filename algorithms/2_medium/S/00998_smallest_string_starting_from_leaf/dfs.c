struct vec {
    char* ptr;
    size_t cap;
    size_t len;
};

static inline bool is_smaller_in_rev(struct vec* stack, struct vec* res) {
    ptrdiff_t res_idx = (ptrdiff_t)res->len - 1;
    ptrdiff_t stack_idx = (ptrdiff_t)stack->len - 1;
    char *restrict res_ptr = res->ptr;
    char *restrict stack_ptr = stack->ptr;

    while (stack_idx >= 0 && res_idx >= 0) {
        if (stack_ptr[stack_idx] < res_ptr[res_idx]) {
            return true;
        } else if (stack_ptr[stack_idx] > res_ptr[res_idx]) {
            return false;
        }

        stack_idx -= 1;
        res_idx -= 1;
    }

    return stack->len < res->len;
}

static inline void push(struct vec* vec, const char ch) {
    if (vec->cap == vec->len) {
        const size_t new_cap = vec->cap == 0 ? 4 : 2 * vec->cap;
        vec->ptr = realloc(vec->ptr, new_cap * sizeof(*vec->ptr));
        if (vec->ptr == NULL) {
            fprintf(stderr, "alloc fail");
            exit(1);
        }
        vec->cap = new_cap;
    }
    vec->ptr[vec->len] = ch;
    vec->len += 1;
}

static inline char* into_str(struct vec* vec) {
    if (vec->cap == vec->len) {
        const size_t new_cap = vec->cap + 1;
        vec->ptr = realloc(vec->ptr, new_cap * sizeof(*vec->ptr));
        if (vec->ptr == NULL) {
            fprintf(stderr, "alloc fail");
            exit(1);
        }
    }
    vec->ptr[vec->len] = '\0';
    char* ptr = vec->ptr;
    vec->ptr = NULL;
    vec->len = 0;
    vec->cap = 0;
    return ptr;
}

static void dfs(struct TreeNode* node, struct vec* stack, struct vec* res) {
    if (node == NULL) {
        return;
    }

    if (node->val > 25 ||  node->val < 0) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    push(stack, (char)(node->val + 'a'));
    if (node->left == NULL && node->right == NULL) {
        if (res->len == 0 || is_smaller_in_rev(stack, res)) {
            if (res->cap < stack->len) {
                const size_t new_cap = stack->len;
                res->ptr = realloc(res->ptr, new_cap * sizeof(*res->ptr));
                if (res->ptr == NULL) {
                    fprintf(stderr, "alloc fail");
                    exit(1);
                }
                res->cap = new_cap;
            }

            const size_t len = stack->len;
            for (size_t i = 0; i < len; i += 1) {
                res->ptr[i] = stack->ptr[i];
            }
            res->len = len;
        }
    }
    dfs(node->left, stack, res);
    dfs(node->right, stack, res);
    stack->len -= 1;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char* smallestFromLeaf(struct TreeNode* root) {
    struct vec res = { .ptr = NULL, .len = 0, .cap = 0 };
    struct vec stack = { .ptr = NULL, .len = 0, .cap = 0 };

    dfs(root, &stack, &res);

    size_t start = 0;
    size_t end = res.len;
    while (start < end) {
        end -= 1;
        const char temp = res.ptr[start];
        res.ptr[start] = res.ptr[end];
        res.ptr[end] = temp;
        start += 1;
    }
/* cleanup: */
    free(stack.ptr);
    return into_str(&res);
}
