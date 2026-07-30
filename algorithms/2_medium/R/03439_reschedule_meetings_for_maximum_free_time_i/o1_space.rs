// O(n) time, O(1) space.
// The problem can be solved without extra allocation,
// but at the cost of complex boundary handling

impl Solution {
    pub fn max_free_time(event_time: i32, k: i32, start_time: Vec<i32>, end_time: Vec<i32>) -> i32 {
        let len = start_time.len();
        assert!(len >= 2 && len == end_time.len() && k >= 1 && (k as usize) <= len && event_time >= 1);
        let k = k as usize;

        let mut prefix = start_time[0];
        for i in 1..=(k.min(len - 1)) {
            prefix += start_time[i] - end_time[i - 1];
        }

        let mut res = prefix;
        
        if k == len {
            return res + event_time - end_time[len - 1];
        }

        for i in (k + 1)..len {
            prefix += start_time[i] - end_time[i - 1];
            prefix -= start_time[i - k - 1] - if i >= k + 2 { end_time[i - k - 2] } else { 0 };
            res = res.max(prefix);
        }

        prefix += event_time - end_time[len - 1];
        prefix -= start_time[len - k - 1] - if len >= k + 2 { end_time[len - k - 2] } else { 0 };
        res = res.max(prefix);

        res
    }
}
