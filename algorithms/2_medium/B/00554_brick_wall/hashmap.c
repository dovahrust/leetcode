static inline int max_int(const int a, const int b) {
    return a > b ? a : b;
}

struct entity {
    bool is_use;
    int64_t key;
    int freq;
};

int leastBricks(int** wall, const int rows, const int* cols_data) {
    assert(rows >= 1 && rows <= 10000 && wall != NULL && cols_data != NULL);
    size_t table_len = 0;
    for (int i = 0; i < rows; i += 1) {
        assert(cols_data[i] > 0);
        table_len += (size_t)(cols_data[i] - 1);
    }
    table_len = table_len * 13 / 10;
    struct entity* table = calloc(table_len, sizeof(*table));
    assert(table != NULL);

    for (int i = 0; i < rows; i += 1) {
        const int* w = wall[i];
        const int cols = cols_data[i];
        int64_t pos = 0;
        for (size_t j = 0; j < cols - 1; j += 1) {
            pos += w[j];
            size_t table_idx = (size_t)pos % table_len;
            while (table[table_idx].is_use) {
                if (table[table_idx].key == pos) {
                    break;
                }
                table_idx = table_idx + 1;
                if (table_idx == table_len) {
                    table_idx = 0;
                }
            }

            table[table_idx].is_use = true;
            table[table_idx].key = pos;
            table[table_idx].freq += 1;
        }
    }

    int max_freq = 0;
    for (size_t i = 0; i < table_len; i += 1) {
        if (table[i].is_use) {
            max_freq = max_int(max_freq, table[i].freq);
        }
    }

/* cleanup: */
    free(table);
    return rows - max_freq;
}
