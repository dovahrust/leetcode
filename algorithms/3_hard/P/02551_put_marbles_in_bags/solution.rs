impl Solution {
    pub fn put_marbles(weights: Vec<i32>, k: i32) -> i64 {
        let k = k as usize;
        if k >= weights.len() || k == 1 { return 0; }

        let mut scores = Vec::with_capacity(weights.len() - 1);

        for w in weights.windows(2) {
            scores.push(w[0] + w[1]);
        }

        scores.sort_unstable();

        let scores_len = scores.len();
        let max: i64 = scores[(scores_len - (k - 1))..scores_len].iter().map(|&x| x as i64).sum();
        let min: i64 = scores[0..(k - 1)].iter().map(|&x| x as i64).sum();

        max - min
    }
}
