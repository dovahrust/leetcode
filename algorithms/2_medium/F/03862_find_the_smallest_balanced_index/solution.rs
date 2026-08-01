impl Solution {
    pub fn smallest_balanced_index(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        debug_assert!(nums.iter().all(|x| *x > 0));

        let mut sum_pref: i64 = nums.iter().map(|n| *n as i64).sum();
        let mut mul_suff = 1 as i64;
        let mut overflow = false;
        for i in (1..len).rev() {
            sum_pref -= nums[i] as i64;

            if sum_pref == mul_suff {
                return i.try_into().unwrap();
            } else if mul_suff > sum_pref {
                break;
            }

            (mul_suff, overflow) = mul_suff.overflowing_mul(nums[i] as i64);
            if overflow {
                return -1;
            }
        }

        -1
    }
}
