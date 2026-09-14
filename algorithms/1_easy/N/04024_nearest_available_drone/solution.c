int nearestDrone(int **drones, const int drone_len, int *drones_cols_data, int *target, int target_len) {
    int res_val = INT_MAX;
    int res_pos = -1;
    const int tx = target[0];
    const int ty = target[1];

    for (int i = 0; i < drone_len; i += 1) {
        const int dx = drones[i][0];
        const int dy = drones[i][1];
        const int dr = drones[i][2];

        const int dist = ABS(tx - dx) + ABS(ty - dy);

        if (dist <= dr && dist < res_val) {
            res_val = dist;
            res_pos = i;
        }
    }

    return res_pos;
}
