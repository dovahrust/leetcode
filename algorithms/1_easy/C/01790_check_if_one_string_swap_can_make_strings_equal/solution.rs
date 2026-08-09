impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        if s1.len() != s2.len() { return false; }
        let (bytes1, bytes2) = (s1.as_bytes(), s2.as_bytes());

        // cnt short-circuits at >2 mismatches, so each freq is only updated for
        // at most two indices; the deltas stay within [-2, 2]. i8 is safe.
        let mut freqs = [0_i8; 256];
        let mut cnt = 0_i32;

        for i in 0..bytes1.len() {
            if bytes1[i] != bytes2[i] {
                cnt += 1;
                if cnt > 2 {
                    return false;
                }
                freqs[bytes1[i] as usize] += 1;
                freqs[bytes2[i] as usize] -= 1;
            }
        }

        freqs.into_iter().all(|freq| freq == 0)
    }
}
