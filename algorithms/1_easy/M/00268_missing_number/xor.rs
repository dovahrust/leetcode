impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let len: i32 = nums.len().try_into().expect("invalid input");
        let mut xor = 0_i32;
        for i in 0..len {
            xor = xor ^ i ^ nums[i as usize];
        }
        xor ^= len;

        xor
    }
}
