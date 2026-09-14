use std::cmp::Reverse;

impl Solution {
    pub fn min_price(mut prices: Vec<i32>, mut discounts: Vec<i32>) -> f64 {
        prices.sort_unstable_by_key(|&x| Reverse(x));
        discounts.sort_unstable_by_key(|&x| Reverse(x));
        let mut discounts_iter = discounts.into_iter();
        let mut res = 0_f64;

        for p in prices {
            if let Some(d) = discounts_iter.next() {
                res += (p as f64) * (100.0_f64 - d as f64) / 100.0_f64;
            } else {
                res += p as f64;
            }
        }

        res
    }
}
