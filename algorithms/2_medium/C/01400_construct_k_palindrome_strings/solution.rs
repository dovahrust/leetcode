impl Solution {
    pub fn can_construct(s: String, k: i32) -> bool {
        assert!(k >= 1);
        let k = k as usize;
        let bytes = s.as_bytes();
        let len = bytes.len();

        if k > len { return false; }

        let mut freqs = [0_usize; 256];

        for &b in bytes {
            freqs[b as usize] += 1;
        }

        let cnt_odd = freqs.into_iter().filter(|&x| (x & 1) == 1).count();

        cnt_odd <= k
    }
}
