struct Solution {
    cnt: Vec<(i32, i32)>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(n: i32, mut blacklist: Vec<i32>) -> Self {
        assert!(n <= 1_000_000_000 && n >= 1);
        if !blacklist.is_empty() {
            blacklist.sort_unstable();
            assert!(blacklist[0] >= 0 && *blacklist.last().unwrap() < n);
        }

        let mut cnt: Vec<(i32, i32)> = Vec::with_capacity(blacklist.len() + 2);
        cnt.push((-1, 0));
        let mut curr = -1;
        for b in blacklist {
            let diff = b - curr - 1;
            let prev = cnt.last().unwrap().1;
            cnt.push((b, diff + prev));
            curr = b;
        }
        let diff = n - curr - 1;
        let prev = cnt.last().unwrap().1;
        cnt.push((n, diff + prev));

        assert!(cnt.last().unwrap().1 > 0);

        Self {
            cnt,
        }
    }

    fn pick(&self) -> i32 {
        let total = self.cnt.last().unwrap().1;
        use rand::Rng;
        let mut rng = rand::thread_rng();
        let random_value = rng.gen_range(1..=total);

        let (mut lo, mut hi) = (0_isize, self.cnt.len() as isize - 1);
        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            if random_value <= self.cnt[mid as usize].1 {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        let total_before_lo = self.cnt[lo as usize].1;
        let offset = total_before_lo - random_value + 1;
        let res = self.cnt[lo as usize].0 - offset;

        res
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(n, blacklist);
 * let ret_1: i32 = obj.pick();
 */
