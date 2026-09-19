impl Solution {
    pub fn minimum_removal(mut beans: Vec<i32>) -> i64 {
        let len = beans.len();
        beans.sort_unstable();
        let total: i64 = beans.iter().map(|&x| x as i64).sum();
        let mut best = total;

        for i in 0..len {
            let w_suff = (len - i) as i64;
            let can_keep = w_suff * beans[i] as i64;
            best = best.min(total - can_keep);
        }

        best
    }
}
