#[derive(Default, Copy, Clone)]
struct FreqCounts {
    by_curr: u32,
    by_hi: u32,
    by_lo: u32,
}

impl Solution {
    pub fn subarrays_with_k_distinct(nums: Vec<i32>, k: i32) -> i32 {
        assert!(k >= 1 && (k as usize) <= nums.len() && nums.len() <= 20_000);
        let len = nums.len();
        let k = k as usize;
        let mut uniques = 0_usize;
        let mut res = 0_usize;
        let mut lo = 0_usize;
        let mut hi = 0_usize;
        let mut freqs = vec![FreqCounts::default(); len + 1];
 
        for curr in 0..len {
            assert!(nums[curr] > 0 && (nums[curr] as usize) <= len);
            if freqs[nums[curr] as usize].by_curr == freqs[nums[curr] as usize].by_lo {
                uniques += 1;
            }
            freqs[nums[curr] as usize].by_curr += 1;
            if uniques >= k {
                while uniques > k {
                    freqs[nums[lo] as usize].by_lo +=1;
                    if freqs[nums[lo] as usize].by_curr == freqs[nums[lo] as usize].by_lo {
                        uniques -= 1;
                    }
                    lo += 1;
                }
                while hi < lo {
                    freqs[nums[hi] as usize].by_hi +=1;
                    hi += 1;
                }
                while freqs[nums[hi] as usize].by_curr - freqs[nums[hi] as usize].by_hi > 1 {
                    freqs[nums[hi] as usize].by_hi +=1;
                    hi += 1;
                }

                res += hi - lo + 1;
            }
        }

        res.try_into().expect("int overflow")
    }
}
