int minMoves(int target, int max_doubles) {
    int cnt = 0;
    while (target > 1) {
        if ((target & 1) == 1) {
            target -= 1;
            cnt += 1;
        } else if (max_doubles > 0) {
            target /= 2;
            max_doubles -= 1;
            cnt += 1;
        } else {
            cnt += target - 1;
            break;
        }
    }

    return cnt;
}
