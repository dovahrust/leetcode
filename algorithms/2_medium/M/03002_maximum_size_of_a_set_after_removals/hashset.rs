use std::collections::HashSet;

impl Solution {
    pub fn maximum_set_size(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        assert!(nums1.len() == nums2.len());
        let len = nums1.len();
        assert!(len > 0 && (len & 1) == 0);

        let half = len / 2;
        let set1: HashSet<i32> = nums1.into_iter().collect();
        let set2: HashSet<i32> = nums2.into_iter().collect();

        let mut cnt1 = 0_usize;
        for num in &set1 {
            if !set2.contains(num) {
                cnt1 += 1;
                if cnt1 == half {
                    break;
                }
            }
        }

        let mut cnt2 = 0_usize;
        for num in &set2 {
            if !set1.contains(num) {
                cnt2 += 1;
                if cnt2 == half {
                    break;
                }
            }
        }

        let mut cnt = cnt1 + cnt2;
        if cnt < len {
            for num in &set1 {
                if set2.contains(num) {
                    cnt += 1;
                    if cnt == len {
                        break;
                    }
                }
            } 
        }

        cnt.try_into().unwrap()
    }
}
