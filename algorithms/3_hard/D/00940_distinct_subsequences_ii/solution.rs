impl Solution {
    const MOD: i64 = 1_000_000_007;

    pub fn distinct_subseq_ii(s: String) -> i32 {
        let bytes = s.as_bytes();
        let mut end_with = [0_i64; 256];
        let mut cnt = 0_i64;

        for &b in bytes {
            let new_end_with = (cnt + 1) % Self::MOD;
            let old_end_with = end_with[b as usize];
            cnt = ((cnt - old_end_with) + new_end_with + Self::MOD) % Self::MOD;
            end_with[b as usize] = new_end_with;
        }

        cnt as i32
    }
}
