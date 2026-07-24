const MAX_ALOWED_NUM: i32 = 10_000;
const MIN_ALOWED_NUM: i32 = -10_000;

impl Solution {
    pub fn longest_subsequence(arr: Vec<i32>, difference: i32) -> i32 {
        assert!(arr.len() > 0);
        if arr.len() == 1 { return 1; }

        let mut max = i32::MIN;
        let mut min = i32::MAX;

        for &a in &arr {
            max = max.max(a);
            min = min.min(a);
        }
        assert!(min >= MIN_ALOWED_NUM && max <= MAX_ALOWED_NUM);

        let table_len = (max - min + 1) as usize;
        let mut table = vec![0_i32; table_len];
        let mut res = 0_i32;

        for a in arr {
            let mut curr = 1_i32;
            if a - difference >= min && a - difference <= max {
                let idx = (a - difference - min) as usize;
                curr = 1 + table[idx];
            }

            table[(a - min) as usize] = curr;
            res = res.max(curr);
        }

        res
    }
}
