impl Solution {
    pub fn min_increment_for_unique(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let mut expect: i32 = i32::MIN;
        let mut needs: i32 = 0;
        for num in nums {
            expect = expect.max(num);
            needs += expect - num;
            expect += 1;
        }

        needs
    }
}
