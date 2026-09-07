int countGroups(
    const int *position, const int position_len,
    const int *speed, const int speed_len,
    const int distance
) {
    if (position_len != speed_len || position_len <= 0 || position == NULL || speed == NULL) { return 0; }

    const int len = speed_len;
    int cnt = 1;
    int min_speed = speed[len - 1];
    int prev_pos = position[len - 1];

    for (int i = len - 2; i >= 0; i -= 1) {
        if (prev_pos - position[i] > distance && speed[i] <= min_speed) {
            min_speed = speed[i];
            cnt += 1;
        }

        prev_pos = position[i];
    }

    return cnt;
}
