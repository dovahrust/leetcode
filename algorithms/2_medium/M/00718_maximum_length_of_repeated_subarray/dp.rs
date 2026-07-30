impl Solution {
    pub fn find_length(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let (n1, n2) = if nums1.len() > nums2.len() { 
            (&nums1, &nums2)
        } else {
            (&nums2, &nums1)
        };
        let (len1, len2) = (n1.len(), n2.len());
        if len1 == 0 || len2 == 0 {
            return 0;
        }
        assert!(len1 <= 1_000);

        let mut buff = vec![0_i16; 2 * (len2 + 1)];
        let (mut curr, mut next) = buff.split_at_mut(len2 + 1);
        let mut res = 0_i16;

        for i in (0..len1).rev() {
            for j in (0..len2).rev() {
                if n1[i] == n2[j] {
                    let val = 1 + next[j + 1];
                    curr[j] = val;
                    res = res.max(val);
                }
            }
            (curr, next) = (next, curr);
            curr.iter_mut().for_each(|x| *x = 0);
        }

        res as i32
    }
}
