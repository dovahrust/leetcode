impl Solution {
    pub fn min_moves(mut target: i32, mut max_doubles: i32) -> i32 {
        let mut cnt: i32 = 0;
        while target > 1 {
            if (target & 1) == 1 {
                target -= 1;
                cnt += 1;
            } else if max_doubles > 0 {
                target /= 2;
                max_doubles -= 1;
                cnt += 1;
            } else {
                cnt += target - 1;
                break;
            }
        }

        cnt
    }
}
