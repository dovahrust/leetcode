use std::cmp::Reverse;

impl Solution {
    pub fn earliest_full_bloom(plant_time: Vec<i32>, grow_time: Vec<i32>) -> i32 {
        let n = plant_time.len();
        let mut combo: Vec<(i32, i32)> = Vec::with_capacity(n);

        for i in 0..n {
            combo.push((plant_time[i], grow_time[i]))
        }

        combo.sort_unstable_by_key(|x| Reverse(x.1));

        let mut res: i32 = 0;
        let mut prev_gt: i32 = 0;

        for (pt, gt) in combo {
            if pt + gt > prev_gt {
                res += pt + gt - prev_gt;
                prev_gt = gt;
            } else {
                prev_gt = prev_gt - pt;
            }
        }

        res
    }
}
