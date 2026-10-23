impl Solution {
    pub fn longest_mountain(arr: Vec<i32>) -> i32 {
        let mut prev: Option<isize> = None;
        let mut curr: isize = 0;
        let mut res: isize = 0;

        for w in arr.windows(2) {
            if w[1] > w[0] {
                if curr <= 0 { 
                    prev = None;
                    curr = 1;
                } else {
                    curr += 1;
                }
            } else if w[1] == w[0] {
                prev = None;
                curr = 0;
            } else {
                if curr > 0 {
                    prev = Some(curr);
                    curr = -1;
                } else {
                    curr -= 1;
                }
            }

            if let Some(p) = prev && curr < 0 {
                res = res.max(1 + p + curr.abs());
            }
        }

        res.try_into().unwrap()
    }
}
