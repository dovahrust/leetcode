impl Solution {
    fn dfs(arr: &[String], idx: usize, seen: u32, valids: &[(u32, bool)]) -> i32 {
        let len = arr.len();
        if idx >= len {
            return 0;
        }

        let (bits, is_valid) = valids[idx];

        let keep = if is_valid && (seen & bits) == 0 {
            (arr[idx].len() as i32) + Self::dfs(arr, idx + 1, seen | bits, valids)
        } else {
            0
        };

        let skip = Self::dfs(arr, idx + 1, seen, valids);

        skip.max(keep)
    }

    pub fn max_length(arr: Vec<String>) -> i32 {
        let len = arr.len();
        assert!(len >= 1 && len <= 16);
        let mut valids = vec![(0_u32, false); len];

        for (i, a) in arr.iter().enumerate() {
            assert!(a.len() <= 26);
            let mut bits = 0_u32;
            let mut is_valid = true;
            for &b in a.as_bytes() {
                assert!(b >= b'a' && b <= b'z');
                let mask = 1_u32 << (b - b'a');
                if (mask & bits) != 0 {
                    is_valid = false;
                    break;
                }
                bits |= mask;
            }
            valids[i] = (bits, is_valid);
        }

        let seen = 0_u32;
        Self::dfs(&arr, 0, seen, &valids)
    }
}
