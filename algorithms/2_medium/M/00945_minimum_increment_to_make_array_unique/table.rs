impl Solution {
    pub fn min_increment_for_unique(nums: Vec<i32>) -> i32 {
        if nums.len() <= 1 { return 0; }

        assert!(nums.len() <= 100_000);
        let mut max = i32::MIN;
        let mut min = i32::MAX;

        for &num in &nums {
            max = max.max(num);
            min = min.min(num);
        }

        let width = ((max as i64) - (min as i64) + 1) as usize;
        let mut freqs = vec![0_u32; width];
        for num in nums {
            freqs[(num - min) as usize] += 1;
        }

        let mut res = 0;
        for i in 0..(width - 1) {
            let freq = freqs[i];
            if freq > 1 {
                res += freq - 1;
                freqs[i] -= freq - 1;
                freqs[i + 1] += freq - 1;
            }
        }

        let last = (freqs[width - 1] - 1) as u64;
        res += (last * (last + 1) / 2) as u32;

        res.try_into().unwrap()
    }
}
