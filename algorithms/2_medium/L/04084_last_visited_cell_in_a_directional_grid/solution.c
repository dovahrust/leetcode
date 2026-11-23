#define VISITED '#'

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lastVisitedCell(char **grid, const int rows, const int *cols_data, int *return_len) {
    const int cols = cols_data[0];
    int i = 0;
    int j = 0;

    while (true) {
        int ni = i;
        int nj = j;

        switch (grid[i][j]) {
            case 'U':
                ni = i - 1;
                break;
            case 'R':
                nj = j + 1;
                break;
            case 'D':
                ni = i + 1;
                break;
            case 'L':
                nj = j - 1;
                break;
            default:
                exit(1);
        };

        if (ni < 0 || nj < 0 || ni >= rows || nj >= cols || grid[ni][nj] == VISITED)  { break; }

        grid[i][j] = VISITED;
        i = ni;
        j = nj;
    }

    int *res = malloc(2 * sizeof(*res));
    if (res == NULL) { return NULL; }

    res[0] = i;
    res[1] = j;
    *return_len = 2;
    return res;
}
