impl Solution {
    const K_MAX: usize = 5;

    pub fn result_array(nums: Vec<i32>, k: i32) -> Vec<i64> {
        debug_assert!(k >= 1 && (k as usize) <= Self::K_MAX);
        let len = nums.len();
        let mut prev = [0_i64; Self::K_MAX];
        let mut sum = [0_i64; Self::K_MAX];
        for num in nums {
            debug_assert!(num >= 1);
            let mut curr = [0_i64; Self::K_MAX];
            let rem = num % k;
            curr[rem as usize] += 1;
            for i in 0..k {
                curr[((i * rem) % k) as usize] += prev[i as usize];
            }
            for i in 0..k {
                sum[i as usize] += curr[i as usize];
            }
            prev = curr;
        }

        sum[0..(k as usize)].to_vec()
    }
}
