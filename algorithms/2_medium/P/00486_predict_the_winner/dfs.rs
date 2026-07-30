impl Solution {
    fn dfs(
        nums: &[i32],
        lo: isize,
        hi: isize,
        p1_turn: bool,
        balance: i32,
    ) -> bool {
        if lo > hi {
            return balance >= 0;
        }
        let len = nums.len();
        let memo_idx = (lo as usize) * len + hi as usize;
        
        if p1_turn {
            return Self::dfs(nums, lo + 1, hi, !p1_turn, balance + nums[lo as usize]) ||
                   Self::dfs(nums, lo, hi - 1, !p1_turn, balance + nums[hi as usize]);
        } else {
            return Self::dfs(nums, lo + 1, hi, !p1_turn, balance - nums[lo as usize]) &&
                   Self::dfs(nums, lo, hi - 1, !p1_turn, balance - nums[hi as usize]);
        }
    }

    pub fn predict_the_winner(nums: Vec<i32>) -> bool {
        let len = nums.len();
        assert!(nums.len() <= 20 && nums.len() >= 1);
        let (lo, hi, p1_turn, balance) = (0_isize, (len - 1) as isize, true, 0_i32);

        Self::dfs(&nums, lo, hi, p1_turn, balance)
    }
}
