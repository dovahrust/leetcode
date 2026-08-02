impl Solution {
    pub fn count_tasks(tasks: Vec<i32>, shifts: Vec<i32>) -> Vec<i32> {
        assert!(tasks.len() >= 1 && tasks.len() <= 100_000);
        let total_tasks = tasks.len() as i32;
        let mut res: Vec<i32> = Vec::with_capacity(shifts.len());
        let mut prefix: Vec<i64> = Vec::with_capacity(tasks.len() + 1);
        unsafe { prefix.set_len(tasks.len() + 1); }
        prefix[0] = 0;
        for (i, t) in tasks.into_iter().enumerate() {
            assert!(t > 0);
            prefix[i + 1] = prefix[i] + t as i64;
        }

        let sum_tasks = *prefix.last().unwrap();
        let mut curr = 0_i64;
        for shift in shifts {
            assert!(shift > 0);
            curr += shift as i64;

            if curr >= sum_tasks {
                curr = 0;
                res.push(0);
            } else {
                match prefix.binary_search(&curr) {
                    Ok(pos) => res.push(total_tasks - pos as i32),
                    Err(pos) => res.push(total_tasks - (pos as i32 - 1)),
                }
            }
        }

        res
    }
}
