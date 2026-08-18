impl Solution {
    pub fn kth_largest_number(mut nums: Vec<String>, k: i32) -> String {
        let len = nums.len();
        assert!(k >= 1 && (k as usize) <= len);
        nums.sort_unstable_by(|a, b| {
            if a.len() != b.len() {
                a.len().cmp(&b.len())
            } else {
                a.cmp(&b)
            }
        });

        nums.swap_remove(len - (k as usize))
    }
}
