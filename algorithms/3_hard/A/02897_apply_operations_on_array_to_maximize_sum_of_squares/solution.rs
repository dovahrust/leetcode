impl Solution {
    const MOD: u64 = 1_000_000_007;
    const INF: u64 = u64::MAX;

    pub fn max_sum(nums: Vec<i32>, k: i32) -> i32 {
        assert!(k >= 1 && (k as usize) <= nums.len());
        let mut freqs = [0_u64; 32];

        for num_i32 in nums {
            let num = num_i32 as u32;
            for i in 0..32_u32 {
                let mask: u32 = (1 << i);
                if (mask & num) != 0 {
                    freqs[i as usize] += 1;
                }
            }
        }

        let mut res: u64 = 0;
        let mut k = k as u64;
        while k > 0 {
            let mut min_freq_non_zero = Self::INF;
            let mut curr: u64 = 0;
            for i in 0..32_u64 {
                if freqs[i as usize] != 0 {
                    min_freq_non_zero = min_freq_non_zero.min(freqs[i as usize]);
                    let mask: u64 = (1 << i);
                    curr |= mask;
                }
            }
            min_freq_non_zero = min_freq_non_zero.min(k);
            k -= min_freq_non_zero;
            let base = (curr * curr) % Self::MOD;
            res = (res + base * min_freq_non_zero) % Self::MOD;

            for i in 0..32 {
                if freqs[i] != 0 {
                    freqs[i] -= min_freq_non_zero;
                }
            }
        }

        res as i32
    }
}
