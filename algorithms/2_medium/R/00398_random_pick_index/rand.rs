struct Solution {
    prefix: Vec<i32>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(mut w: Vec<i32>) -> Self {
        assert!(w.len() >= 1 && w.len() <= 10_000);
        assert!(w.iter().all(|v| *v >= 1 && *v <= 100_000));

        for i in 1..w.len() {
            w[i] += w[i - 1];
        }

        Self {
            prefix: w
        }
    }

    fn pick_index(&self) -> i32 {
        let max = *self.prefix.last().unwrap();
        use rand::Rng;
        let mut rng = rand::thread_rng();
        let random_value: i32 = rng.gen_range(1..=max);
        let (mut lo, mut hi) = (0_isize, self.prefix.len() as isize - 1);
        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            if random_value <= self.prefix[mid as usize] {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        lo.try_into().unwrap()
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(w);
 * let ret_1: i32 = obj.pick_index();
 */
