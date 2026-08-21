struct Solution {
    valids: Vec<i32>,
    valids_len: usize,
    m: i32,
    n: i32,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(m: i32, n: i32) -> Self {
        assert!(n >= 1 && m >= 1 && n <= 10_000 && m <= 10_000);
        let total = n * m;

        Self {
            valids: (0..total).collect(),
            valids_len: total as usize,
            m: m,
            n: n,
        }
    }

    fn flip(&mut self) -> Vec<i32> {
        if self.valids_len == 0 {
            return Vec::default();
        }

        use rand::Rng;
        let mut rng = rand::thread_rng();
        let random_value: usize = rng.gen_range(0..self.valids_len);
        let res = self.valids[random_value];
        self.valids[random_value] = self.valids[self.valids_len - 1];
        self.valids[self.valids_len - 1] = res;

        self.valids_len -= 1;

        vec![res / self.n, res % self.n]
    }

    fn reset(&mut self) {
        let total = self.n * self.m;
        self.valids_len = total as usize;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(m, n);
 * let ret_1: Vec<i32> = obj.flip();
 * obj.reset();
 */
