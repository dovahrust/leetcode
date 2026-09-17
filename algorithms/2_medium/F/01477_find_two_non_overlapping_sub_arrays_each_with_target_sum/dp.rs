impl Solution {
    const INF: usize = usize::MAX;

    pub fn min_sum_of_lengths(arr: Vec<i32>, target: i32) -> i32 {
        assert!(target > 0 && arr.iter().all(|&x| x > 0));
        let len = arr.len();
        if len <= 1 { return -1; }

        let mut dp = vec![Self::INF; len + 1];
        let mut res: Option<usize> = None;
        let mut lo: usize = 0;
        let mut curr_sum: i32 = 0;
        for hi in 0..len {    
            curr_sum += arr[hi];
            while curr_sum > target {
                curr_sum -= arr[lo];
                lo += 1;
            }

            if curr_sum == target {
                let w = hi + 1 - lo;
                dp[hi + 1] = w.min(dp[hi]);

                if dp[lo] != Self::INF {
                    match res {
                        None => res = Some(w + dp[lo]),
                        Some(val) => res = Some(val.min(w + dp[lo])),
                    }
                }
            } else {
                dp[hi + 1] = dp[hi];
            }
        }

        match res {
            None => -1,
            Some(val) => val.try_into().unwrap(),
        }
    }
}
