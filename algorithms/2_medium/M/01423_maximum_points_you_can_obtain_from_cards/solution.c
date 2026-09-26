int maxScore(const int *restrict card_points, const int len, const int k) {
    assert(k >= 1 && k <= len);
    int score = 0;
    for (int i = len - k; i < len; i += 1) {
        score += card_points[i];
    }
    int max_score = score;

    for (int i = 0; i < k; i += 1) {
        score -= card_points[len - k + i];
        score += card_points[i];
        max_score = MAX(max_score, score);
    }

    return max_score;
}
