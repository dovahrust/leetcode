impl Solution {
    pub fn can_three_parts_equal_sum(arr: Vec<i32>) -> bool {
        let sum: i32 = arr.iter().sum();
        if (sum % 3) != 0 {
            return false;
        }

        let target = sum / 3;
        let mut cnt = 0;
        let mut curr_sum = 0;
        for a in arr {
            curr_sum += a;
            if curr_sum == target {
                cnt += 1;
                if cnt == 3 {
                    return true;
                }
                curr_sum = 0;
            }
        }

        false
    }
}
