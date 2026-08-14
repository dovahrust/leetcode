impl Solution {
    pub fn advantage_count(mut nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let len = nums1.len();
        assert!(len == nums2.len() && len >= 1 && len <= 100_000);

        let mut combo2: Vec<(i32, u32)> = nums2.into_iter().enumerate().map(|(i, v)| (v, i as u32)).collect();
        let mut res = vec![0_i32; len];

        nums1.sort_unstable();
        combo2.sort_unstable();

        let (mut begin, mut end) = (0_usize, len);

        for (num, idx) in combo2.into_iter().rev() {
            if num < nums1[end - 1] {
                res[idx as usize] = nums1[end - 1];
                end -= 1;
            } else {
                res[idx as usize] = nums1[begin];
                begin += 1;
            }
        }

        res
    }
}
