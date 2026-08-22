use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn max_score(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> i64 {
        assert!(nums1.len() == nums2.len() && k >= 1 && (k as usize) <= nums1.len());

        let len = nums1.len();
        let k = k as usize;
        let mut combo = Vec::with_capacity(len);
        unsafe { combo.set_len(len); }
        for i in 0..len {
            combo[i] = (nums2[i], nums1[i]);
        }
        combo.sort_unstable();
        let mut heap: BinaryHeap<Reverse<i32>> = BinaryHeap::with_capacity(k + 1);
        let mut sum = 0_i64;
        let mut res = i64::MIN;

        for i in (0..len).rev() {
            heap.push(Reverse(combo[i].1));
            sum += combo[i].1 as i64;
            if heap.len() > k {
                let Reverse(top) = heap.pop().unwrap();
                sum -= top as i64;
            }
            if heap.len() == k {
                let min_n2 = combo[i].0 as i64;
                res = res.max(min_n2 * sum);
            }
        }

        res
    }
}
