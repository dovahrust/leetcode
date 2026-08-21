use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn k_smallest_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        assert!(
            k >= 1 && (k as usize) <= nums1.len() * nums2.len() &&
            nums1.len() > 0 && nums1.len() <= 100_000 &&
            nums2.len() > 0 && nums2.len() <= 100_000
        );

        let len1 = nums1.len();
        let k = k as usize;
        let mut heap = BinaryHeap::with_capacity(k.min(len1));
        for i in 0..(k.min(len1)) {
            heap.push(Reverse((nums1[i] + nums2[0], i as i32, 0_i32)));
        }
        let mut res: Vec<Vec<i32>> = Vec::with_capacity(k);
        let len2 = nums2.len() as i32;

        for _ in 0..k {
            let (Reverse((sum, idx1, idx2))) = heap.pop().unwrap();
            res.push(vec![nums1[idx1 as usize], nums2[idx2 as usize]]);
            if idx2 + 1 < len2 {
                heap.push(Reverse((nums1[idx1 as usize] + nums2[(idx2 + 1) as usize], idx1, idx2 + 1)));
            }
        }

        res
    }
}
