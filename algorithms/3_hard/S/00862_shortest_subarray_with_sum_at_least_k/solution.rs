use std::collections::VecDeque;

impl Solution {
    pub fn shortest_subarray(nums: Vec<i32>, k: i32) -> i32 {
        assert!(k > 0);
        let k = k as i64;
        let mut res: Option<isize> = None;
        let mut sum = 0_i64;
        let mut q: VecDeque<(isize, i64)> = VecDeque::new();
        q.push_back((-1, 0));

        for (i, num) in nums.into_iter().enumerate() {
            sum += num as i64;

            while let Some((_, val)) = q.back() && *val >= sum {
                q.pop_back();
            }

            while let Some((idx, val)) = q.front() && sum - *val >= k {
                res = Some(res.unwrap_or(isize::MAX).min((i as isize) - idx));
                q.pop_front();
            }

            q.push_back((i as isize, sum));
        }

        match res {
            Some(val) => val.try_into().unwrap(),
            None => -1,
        }
    }
}
