use std::collections::HashMap;

struct Solution {
    map: HashMap<i32, i32>,
    range: i32,
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
            map: HashMap::new(),
            range: total,
            m: m,
            n: n,
        }
    }

    fn flip(&mut self) -> Vec<i32> {
        if self.range == 0 {
            return Vec::default();
        }

        use rand::Rng;
        let mut rng = rand::thread_rng();
        let random_value: i32 = rng.gen_range(0..self.range);

        let res = match self.map.get(&random_value) {
            None => random_value,
            Some(v) => *v,
        };

        self.range -= 1;
        match self.map.get(&self.range) {
            None => self.map.insert(random_value, self.range),
            Some(v) => self.map.insert(random_value, *v),
        };

        vec![res / self.n, res % self.n]
    }

    fn reset(&mut self) {
        let total = self.n * self.m;
        self.map.clear();
        self.range = total;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(m, n);
 * let ret_1: Vec<i32> = obj.flip();
 * obj.reset();
 */
