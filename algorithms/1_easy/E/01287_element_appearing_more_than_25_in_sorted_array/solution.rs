impl Solution {
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        let target_cnt: usize = arr.len() / 4;
        let mut cnt: usize = 0;
        let mut curr: i32 = 0;

        for a in arr {
            if curr != a {
                curr = a;
                cnt = 1;
            } else {
                cnt += 1;
            }

            if cnt > target_cnt {
                return curr;
            }
        }

        unreachable!()
    }
}
