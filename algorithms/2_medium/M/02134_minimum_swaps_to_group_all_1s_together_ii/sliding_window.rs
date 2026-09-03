impl Solution {
    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let ones = nums.iter().filter(|&&x| x == 1).count();
        
        if ones <= 1 || (len - ones) <= 1 {
            return 0;
        }

        let mut freq_window = nums[(len - ones)..len].iter().filter(|&&x| x == 1).count();
        let mut need = ones - freq_window;

        for i in 0..(len - 1) {
            if nums[i] == 1 {
                freq_window += 1;
            }

            if nums[(len - ones + i) % len] == 1 {
                freq_window -= 1;
            }

            need = need.min(ones - freq_window);
        }

        need.try_into().unwrap()
    }
}
