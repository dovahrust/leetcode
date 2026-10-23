impl Solution {
    pub fn max_sum_of_squares(num: i32, mut sum: i32) -> String {
        if num * 9 < sum { return "".to_string(); }

        let mut res: Vec<u8> = Vec::with_capacity(1 + num as usize);
        unsafe { res.set_len(num as usize); }

        for i in 0..(num as usize) {
            let curr_dig = sum.min(9);
            sum -= curr_dig;
            res[i] = b'0' + curr_dig as u8;
        }

        String::from_utf8(res).unwrap()
    }
}
