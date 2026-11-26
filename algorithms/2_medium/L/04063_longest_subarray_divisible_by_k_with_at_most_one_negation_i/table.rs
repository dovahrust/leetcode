impl Solution {
    pub fn longest_subarray(nums: Vec<i32>, k: i32) -> i32 {
        let len = nums.len();
        let mut set: Vec<u8> = vec![0; k as usize];
        let mut stamp: u8 = 0;
        let mut max: usize = 0;

        for i in 0..len {
            if stamp == u8::MAX {
                stamp = 1;
                set.iter_mut().for_each(|x| *x = 0);
            } else {
                stamp += 1;
            }

            let mut sum_mod: i32 = 0;
            for j in i..len {
                let mod_by_k = ((nums[j] % k) + k) % k;
                sum_mod = (sum_mod + mod_by_k) % k;

                if mod_by_k != 0 {
                    let mod_by_k_comp = k - mod_by_k;
                    set[((mod_by_k - mod_by_k_comp + k) % k) as usize] = stamp;
                }
                
                if sum_mod == 0 || set[sum_mod as usize] == stamp {
                    max = max.max(j - i + 1);
                }
            }
        }

        max.try_into().unwrap()
    }
}
