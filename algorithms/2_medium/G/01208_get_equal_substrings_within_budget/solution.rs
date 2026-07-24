impl Solution {
    pub fn equal_substring(s: String, t: String, max_cost: i32) -> i32 {
        let (s_bytes, t_bytes) = (s.as_bytes(), t.as_bytes());

        assert!(s_bytes.len() == t_bytes.len() && max_cost >= 0);

        let len = s_bytes.len();
        let mut lo = 0_usize;
        let mut res = 0_usize;
        let mut cost = 0_i32;

        for hi in 0..len {
            cost += (s_bytes[hi] as i32 - t_bytes[hi] as i32).abs();
            while cost > max_cost {
                cost -= (s_bytes[lo] as i32 - t_bytes[lo] as i32).abs();
                lo += 1;
            }
            res = res.max(hi + 1 - lo);
        }

        res.try_into().unwrap()
    }
}
