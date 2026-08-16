#define MAX_ALLOWED 100

int findChampion(const int n, int** edges, const int len, const int* cols) {
    if (n < 1 || n > MAX_ALLOWED) {
        goto invalid_input;
    }

    int8_t parent[MAX_ALLOWED];
    for (int i = 0; i < n; i += 1) { parent[i] = -1; }

    for (int i = 0; i < len; i += 1) {
        const int u = edges[i][0];
        const int v = edges[i][1];

        if (u < 0 || v < 0 || u >= n || v >= n) {
            goto invalid_input;
        }

        parent[v] = (int8_t)u;
    }

    int res = -1;
    for (int i = 0; i < n; i += 1) {
        if (parent[i] == -1) {
            if (res == -1) {
                res = i;
            } else {
                return -1;
            }
        }
    }

    return res;

invalid_input:
    fprintf(stderr, "invalid input\n");
    exit(1);
}
