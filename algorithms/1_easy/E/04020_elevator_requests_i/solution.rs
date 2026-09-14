impl Solution {
    pub fn elevator_requests(n: i32, requests: Vec<i32>) -> i32 {
        let mut prev = 0_i32;
        let mut res = 0_i32;

        for r in requests {
            res += (prev - r).abs();
            prev = r;
        }

        res
    }
}
