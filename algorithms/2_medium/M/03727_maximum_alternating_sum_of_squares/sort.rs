impl Solution {
    pub fn max_alternating_sum(mut nums: Vec<i32>) -> i64 {
        nums.sort_unstable_by_key(|x| x.abs());

        let plus_index = nums.len() / 2;
        let mut t_sum = 0_i64;

        nums[0..plus_index].iter().for_each(|&x| t_sum -= (x as i64).pow(2));
        nums[plus_index..].iter().for_each(|&x| t_sum += (x as i64).pow(2));

        t_sum
    }
}
