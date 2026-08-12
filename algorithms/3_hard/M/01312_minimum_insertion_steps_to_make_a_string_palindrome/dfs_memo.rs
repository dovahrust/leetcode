impl Solution {
    fn dfs(bytes: &[u8], lo: usize, hi: usize, memo: &mut[i16]) -> i16 {
        if lo >= hi {
            return 0;
        }

        let len = bytes.len();
        let memo_idx = lo * len + hi; 
        if memo[memo_idx] != -1 {
            return memo[memo_idx];
        }

        let mut res = i16::MAX;

        if bytes[lo] == bytes[hi] {
            res = Self::dfs(bytes, lo + 1, hi - 1, memo);
        } else {
            res = 1 + Self::dfs(bytes, lo + 1, hi, memo)
                      .min(Self::dfs(bytes, lo, hi - 1, memo));
        }

        memo[memo_idx] = res;
        res
    }

    pub fn min_insertions(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        assert!(len >= 1 && len <= 500);

        let mut memo = vec![-1_i16; len * len];

        Self::dfs(bytes, 0, len - 1, &mut memo) as i32
    }
}
