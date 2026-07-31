impl Solution {
    #[inline(always)]
    fn is_ok(prices: &[i32], mut k: i32, mid: i32) -> bool {
        k -= 1;
        let mut curr = prices[0];

        for &p in prices.into_iter().skip(1) {
            if p - curr >= mid {
                k -= 1;
                curr = p;

                if k == 0 {
                    return true;
                }
            }
        }

        false
    }

    pub fn maximum_tastiness(mut prices: Vec<i32>, k: i32) -> i32 {
        assert!(k >= 2 && (k as usize) <= prices.len() && prices.len() <= 100_000);
        let mut lo = 0;
        let mut hi = i32::MAX;
        prices.sort_unstable();

        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            if Self::is_ok(&prices, k, mid) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        hi
    }
}
