impl Solution {
    pub fn max_sum_of_three_subarrays(nums: Vec<i32>, k: i32) -> Vec<i32> {
        assert!(k >= 1);
        let k = k as usize;
        let len = nums.len();
        assert!(k <= len / 3 && len <= 20_000);

        let mut prefix_sum = vec![0_i32; len + 1];
        for i in 0..len {
            assert!(nums[i] >= 1 && nums[i] <= 2_i32.pow(16));
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        let mut buff = vec![(0_i32, 0_i32); (len + 1) * 2];
        let (mut prefix_max, mut suffix_max) = buff.split_at_mut(len + 1);

        for i in 0..=(len - k) {
            let curr = prefix_sum[i + k] - prefix_sum[i];
            if i == 0 || curr > prefix_max[i - 1].0 {
                prefix_max[i] = (curr, i as i32);
            } else {
                prefix_max[i] = prefix_max[i - 1];
            }
        }

        for i in (0..=(len - k)).rev() {
            let curr = prefix_sum[i + k] - prefix_sum[i];
            if curr >= suffix_max[i + 1].0 {
                suffix_max[i] = (curr, i as i32);
            } else {
                suffix_max[i] = suffix_max[i + 1];
            }
        }

        let mut sum = 0_i32;
        let mut res = vec![0_i32; 3];

        for i in k..=(len - k - k) {
            let curr_sum = prefix_sum[i + k] - prefix_sum[i] +
                           prefix_max[i - k].0 + 
                           suffix_max[i + k].0;

            if curr_sum > sum {
                sum = curr_sum;
                (res[0], res[1], res[2]) = (prefix_max[i - k].1, i as i32, suffix_max[i + k].1); 
            }
        }

        res
    }
}
