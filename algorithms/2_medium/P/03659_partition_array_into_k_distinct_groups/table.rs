impl Solution {
    pub fn partition_array(nums: Vec<i32>, k: i32) -> bool {

        assert!(nums.iter().all(|&x| x >= 1 && x <= 100_000));
        assert!(nums.len() <= 100_000 && !nums.is_empty() && k >= 1);

        let len = nums.len() as i32;
        if len % k != 0 { return false; }

        let max_allow = len / k;
        let mut freqs = vec![0_i32; (*nums.iter().max().unwrap() as usize) + 1];

        for num in nums {
            let entry = &mut freqs[num as usize];
            *entry += 1;

            if *entry > max_allow { return false; }
        }

        true
    }
}
