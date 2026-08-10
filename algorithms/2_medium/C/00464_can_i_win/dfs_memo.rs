impl Solution {
    fn dfs(curr: u32, seen: u32, max_valid: u32, target: u32, memo: &mut[i8]) -> bool {
        if memo[seen as usize] != -1 {
            return if memo[seen as usize] == 0 { false } else { true };
        }

        let mut res = false;
        for i in 1..=max_valid {
            let mask = (1_u32 << (i - 1));
            if (seen & mask) == 0 {
                if curr + i >= target {
                    res = true;
                    break;
                } else {
                    res = !Self::dfs(curr + i, seen | mask, max_valid, target, memo);
                    if (res == true) {
                        break;
                    }
                }
            }
        }

        memo[seen as usize] = if res { 1 } else { 0 };
        res
    }

    pub fn can_i_win(max_valid: i32, target: i32) -> bool {
        assert!(max_valid >= 1 && max_valid <= 20 && target >= 0 && target <= 300);
        if max_valid >= target {
            return true;
        }

        let sum = max_valid * (max_valid + 1) / 2;
        if sum < target {
            return false;
        }

        let memo_len = (1_usize << (max_valid as usize));
        let mut memo = vec![-1_i8; memo_len];

        Self::dfs(0_u32, 0_u32, max_valid as u32, target as u32, &mut memo)
    }
}
