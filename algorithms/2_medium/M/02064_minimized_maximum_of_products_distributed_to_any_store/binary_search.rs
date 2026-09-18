use std::cmp::Ordering;

impl Solution {
    #[inline(always)]
    fn groups_state(arr: &[i32], val: i32, target: i32) -> Ordering {
        let mut cnt = 0_i32;
        for &a in arr {
            cnt +=  (a + val - 1) / val;
            if cnt > target {
                return Ordering::Greater;
            }
        }

        if cnt == target {
            return Ordering::Equal;
        }

        Ordering::Less
    }

    pub fn minimized_maximum(n: i32, quantities: Vec<i32>) -> i32 {
        assert!((n as usize) >= quantities.len() && !quantities.is_empty());

        let max_num = *quantities.iter().max().unwrap();
        let mut lo: i32 = 1;
        let mut hi: i32 = max_num;

        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            match Self::groups_state(&quantities, mid, n) {
                Ordering::Greater => lo = mid + 1,
                _ => hi = mid - 1,
            }
        }

        lo
    }
}
