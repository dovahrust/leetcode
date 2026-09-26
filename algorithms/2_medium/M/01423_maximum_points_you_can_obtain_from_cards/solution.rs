impl Solution {
    pub fn max_score(card_points: Vec<i32>, k: i32) -> i32 {
        assert!(k >= 1 && (k as usize) <= card_points.len());
        let k = k as usize;
        let len = card_points.len();
        let mut score: i32 = card_points[(len - k)..len].iter().sum();
        let mut max_score = score;

        for i in 0..k {
            score -= card_points[len - k + i];
            score += card_points[i];
            max_score = max_score.max(score);
        }

        max_score
    }
}
