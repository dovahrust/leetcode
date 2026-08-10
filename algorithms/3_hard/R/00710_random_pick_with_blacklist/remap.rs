use std::collections::HashMap;

struct Solution {
    remap: HashMap<i32, i32>,
    valids: i32,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(n: i32, blacklist: Vec<i32>) -> Self {
        assert!(n <= 1_000_000_000 && n >= 1 && blacklist.len() < n as usize);
        let valids = n - blacklist.len() as i32;
        let bl = blacklist.iter().filter(|&&x| x >= valids).map(|x| *x).collect::<std::collections::HashSet<i32>>();
        let mut remap: HashMap<i32, i32> = HashMap::new();
        let mut up = n;

        for b in blacklist {
            if b < valids {
                up -= 1;
                while bl.contains(&up) {
                    up -= 1;
                }
                remap.insert(b, up);
            }
        }

        Self {
            remap,
            valids,
        }
    }

    fn pick(&self) -> i32 {
        use rand::Rng;
        let mut rng = rand::thread_rng();
        let random_value = rng.gen_range(0..self.valids);

        *self.remap.get(&random_value).unwrap_or(&random_value)
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(n, blacklist);
 * let ret_1: i32 = obj.pick();
 */
