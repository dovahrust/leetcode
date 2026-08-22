impl Solution {
    pub fn get_winner(arr: Vec<i32>, k: i32) -> i32 {
        assert!(k >= 1 && arr.len() >= 2);

        let len = arr.len();
        let mut cnt = 0_i32;
        let mut curr = arr[0];

        // Because all integers are distinct, each comparison has a clear winner.
        // If `curr` wins, its streak increases; otherwise a new winner starts.
        // We only need to scan once: if no element reaches `k` wins before
        // the maximum appears, the maximum itself will win all later comparisons.
        for i in 1..len {
            if curr > arr[i] {
                cnt += 1;
            } else {
                cnt = 1;
                curr = arr[i];
            }

            if cnt >= k {
                return curr;
            }
        }

        // The maximum element is guaranteed to win in the end.
        curr
    }
}
