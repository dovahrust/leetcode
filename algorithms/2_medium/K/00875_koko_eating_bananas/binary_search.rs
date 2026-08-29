impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let mut hi: i32 = *piles.iter().max().unwrap();
        let mut lo: i32 = 1;

        while lo <= hi {
            let mid = lo + (hi - lo) / 2;

            let mut total = 0_i32;
            for &p in &piles {
                total += (p + mid - 1) / mid;
                if total > h {
                    break;
                }
            }

            if total <= h {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        lo
    }
}
