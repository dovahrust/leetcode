impl Solution {
    pub fn max_free_time(event_time: i32, k: i32, start_time: Vec<i32>, end_time: Vec<i32>) -> i32 {
        assert!(start_time.len() == end_time.len() && k >= 1 && event_time >= 1);
        let len = start_time.len();
        let k = k as usize;

        let mut prefix: Vec<i32> = Vec::with_capacity(len + 2);
        unsafe { prefix.set_len(len + 2); }
        prefix[0] = 0;
        let mut prev_end = 0_i32;
        for i in 0..len {
            prefix[i + 1] = prefix[i] + start_time[i] - prev_end;
            prev_end = end_time[i];
        }
        prefix[len + 1] = event_time - prev_end + prefix[len];

        let mut res = 0_i32;
        for i in (k - 1)..len {
            let curr = prefix[i + 2] - prefix[i - (k - 1)];
            res = res.max(curr);
        }

        res
    }
}
