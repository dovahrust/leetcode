impl Solution {
    pub fn longest_subsequence(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut xor = 0_i32;
        let mut zeros = 0_usize;

        for num in nums {
            xor ^= num;
            if num == 0 {
                zeros += 1;
            } 
        }

        if zeros == len {
            return 0;
        }

        if xor != 0 {
            return len as i32;
        }

        len as i32 - 1
    }
}
