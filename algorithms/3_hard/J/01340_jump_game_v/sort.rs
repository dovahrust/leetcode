use std::cmp::Reverse;

impl Solution {
    pub fn max_jumps(arr: Vec<i32>, d: i32) -> i32 {
        let d = d as usize;
        let len = arr.len();
        let mut dp = vec![1_usize; len];
        let mut combo: Vec<(usize, i32)> = arr.iter().map(|x| *x).enumerate().collect();
        combo.sort_unstable_by_key(|x| Reverse(x.1));

        for (idx, curr_h) in combo {
            let curr_dp = dp[idx];

            for i in ((idx + 1)..len).take(d) {
                if arr[i] >= curr_h { break; }

                dp[i] = dp[i].max(curr_dp + 1);
            }

            for i in (0..idx).rev().take(d) {
                if arr[i] >= curr_h { break; }

                dp[i] = dp[i].max(curr_dp + 1);
            }
        }

        dp.into_iter().max().unwrap().try_into().unwrap()
    }
}
