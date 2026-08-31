typedef ptrdiff_t isize;

__attribute__((no_sanitize("all")))
static bool dfs(
    const char** board, const int rows, const int cols,
    const int i, const int j,
    const char* word, const isize word_idx,
    bool *restrict is_visited
) {
    if (word[word_idx] == '\0') {
        return true;
    }

    if (i < 0 || i >= rows || j < 0 || j >= cols || is_visited[i * cols + j] || board[i][j] != word[word_idx]) {
        return false;
    }

    is_visited[i * cols + j] = true;

    const bool res = dfs(board, rows, cols, i + 1, j, word, word_idx + 1, is_visited) ||
                     dfs(board, rows, cols, i - 1, j, word, word_idx + 1, is_visited) ||
                     dfs(board, rows, cols, i, j + 1, word, word_idx + 1, is_visited) ||
                     dfs(board, rows, cols, i, j - 1, word, word_idx + 1, is_visited);

    is_visited[i * cols + j] = false;

    return res;
}

void clean_is_visited(void *p)  {
    void *ptr = *(void **)p;
    free(ptr);
}

__attribute__((no_sanitize("all")))
bool exist(
    char **board, const int rows, const int *restrict cols_data,
    const char *word
) {
    if (rows < 0 || board == NULL || word == NULL || cols_data == NULL || cols_data[0] < 0) { return false; }

    const int cols = cols_data[0];
    bool *is_visited __attribute__((cleanup(clean_is_visited))) = 
            (bool *) calloc(((size_t)rows * (size_t)cols), sizeof(*is_visited));

    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (dfs((const char**) board, rows, cols, i, j, word, 0, is_visited)) {
                return true;
            }
        }
    }

    return false;
}
