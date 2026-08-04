impl Solution {
    pub fn find_missing_elements(nums: Vec<i32>) -> Vec<i32> {
        assert!(nums.len() > 0);
        let max: i32 = *nums.iter().max().unwrap();
        let min: i32 = *nums.iter().min().unwrap();
        let seen_len = ((max as i64) - (min as i64) + 1) as usize;
        let mut seen = vec![false; seen_len];
        let mut res_len = seen_len;

        for num in nums {
            let idx = ((num as i64) - (min as i64)) as usize;
            if !seen[idx] {
                res_len -= 1;
                seen[idx] = true;
            }
        }

        let mut res: Vec<i32> = Vec::with_capacity(res_len);
        for val in min..max {
            let idx = ((val as i64) - (min as i64)) as usize;
            if !seen[idx] {
                res.push(val);
            }
        }

        res
    }
}
