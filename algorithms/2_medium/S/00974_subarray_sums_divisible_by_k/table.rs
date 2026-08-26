impl Solution {
    pub fn subarrays_div_by_k(nums: Vec<i32>, k: i32) -> i32 {
        assert!(k >= 2 && k <= 10_000 && nums.len() <= 30_000);
        let mut freqs = vec![0_i32; k as usize];
        let mut sum = 0_i32;
        freqs[0] = 1;

        for num in nums {
            sum += num;
            freqs[(((sum % k) + k) % k) as usize] += 1;
        }

        freqs.into_iter().map(|x| x  * (x - 1) / 2).sum::<i32>()
    }
}
