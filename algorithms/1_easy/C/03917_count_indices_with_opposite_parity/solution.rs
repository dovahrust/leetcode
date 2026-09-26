impl Solution {
    pub fn count_opposite_parity(mut nums: Vec<i32>) -> Vec<i32> {
        let (mut o, mut e): (i32, i32) = (0, 0);

        for num in nums.iter_mut().rev() {
            if (*num & 1) == 1 {
                o += 1;
                *num = e;
            } else {
                e += 1;
                *num = o;
            }
        }

        nums
    }
}
