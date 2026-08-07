impl Solution {
    pub fn count_triplets(nums: Vec<i32>) -> i32 {
        debug_assert!(!nums.is_empty() && nums.iter().all(|x| *x >= 0 && *x < 2_i32.pow(16)));
        let max = *nums.iter().max().unwrap();
        let mut table_len = 1_usize;
        while table_len <=  max as usize {
            table_len <<= 1;
        }
        let mut table = vec![0_i32; table_len];
        for &n1 in &nums {
            for &n2 in &nums {
                table[(n1 & n2) as usize] += 1;
            }
        } 

        let mut cnt = 0_i32;
        for (i, &freq) in table.iter().enumerate() {
            if freq == 0 {
                continue;
            }
            let other = i as i32;
            for &num in &nums {
                if (num & other) == 0 {
                    cnt += freq;
                }
            }
        }

        cnt
    }
}
